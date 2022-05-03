from tkinter import *
import tkinter.messagebox as box
from tkinter import colorchooser
from math import *
import copy
import numpy as np
import matplotlib.pyplot as plt
from time import time, sleep
import colorutils as cu

CV_WIDE = 800
CV_HEIGHT = 800
CV_COLOR = "#ffffff" #f3e6ff" #"#cce6ff"
MAIN_TEXT_COLOR = "#b566ff" #"lightblue" a94dff
TEXT_COLOR = "#ce99ff"

TEMP_SIDE_COLOR_CHECK = (255, 0, 255) # purple
TEMP_SIDE_COLOR = "#ff00ff"

BOX_COLOR = "#dab3ff"

COLOR_LINE = "#000002" #(0, 0, 0) # black
COLOR_LINE_CHECK = (0, 0, 2)

FILL_COLOR = "#ff6e41"

dots = [[]]
seed_dot = []

current_color = ((255, 0, 0), 0)

def show_info(str):
    box.showinfo("Информация", str)
    return

def show_error(str):
    box.showerror("Error", str)
    return

def draw_dot(x, y, color):
    image_canvas.put(color, (x, y))

def sign(difference):
    if (difference < 0):
        return -1
    elif (difference == 0):
        return 0
    else:
        return 1

def choose_color():
    global current_color
    current_color = colorchooser.askcolor()

def bresenham_int(p1, p2, color):
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]

    if (x2 - x1 == 0) and (y2 - y1 == 0):
        return [[x1, y1, color]]

    x = x1
    y = y1

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    s1 = sign(x2 - x1)
    s2 = sign(y2 - y1)

    if (dy > dx):
        tmp = dx
        dx = dy
        dy = tmp
        swaped = 1
    else:
        swaped = 0

    e = 2 * dy - dx
    i = 1

    while (i <= dx + 1):
        draw_dot(x, y, color)

        while (e >= 0):
            if (swaped):
                x = x + s1
            else:
                y = y + s2

            e = e - 2 * dx

        if (swaped):
            y = y + s2
        else:
            x = x + s1

        e = e + 2 * dy

        i += 1

def read_dot():
    try:
        x = float(x_entry.get())
        y = float(y_entry.get())
    except:
        show_error("Неверно введены координаты точки")
        return

    add_dot(int(x), int(y))

def add_dot_click(event):
    x = event.x
    y = event.y

    add_dot(x, y)

def add_seed_dot_click(event):
    global seed_dot

    x = event.x
    y = event.y

    seed_dot = [x, y]

    x_seed_entry.delete(0, END)
    x_seed_entry.insert(END, "%d" %(x))
    y_seed_entry.delete(0, END)
    y_seed_entry.insert(END, "%d" %(y))

def add_dot(x, y, last = True):
    cur_figure = len(dots) - 1
    dots[cur_figure].append([x, y])

    cur_dot = len(dots[cur_figure]) - 1

    if (last):
        dotslist_box.insert(END, "%d. (%4d;%4d)" %(cur_dot + 1, x, y))

    if (len(dots[cur_figure]) > 1):
        bresenham_int(dots[cur_figure][cur_dot - 1], dots[cur_figure][cur_dot], COLOR_LINE)
        
def del_dot():
    cur_figure = len(dots) - 1
    cur_dot = len(dots[cur_figure]) - 1

    if (len(dots[cur_figure]) == 0):
        return

    if (len(dots[cur_figure]) > 1):
        bresenham_int(dots[cur_figure][cur_dot - 1], dots[cur_figure][cur_dot], "white")
    index = 0

    for i in range(cur_figure + 1):
        index += len(dots[i])
    dotslist_box.delete(index - 1, END)

    dots[cur_figure].pop(len(dots[cur_figure]) - 1)

def make_figure():
    cur_figure = len(dots)
    cur_dot = len(dots[cur_figure - 1])

    if (cur_dot < 3):
        show_error("Недостаточно точек, чтобы замкнуть фигуру")

    add_dot(dots[cur_figure - 1][0][0], dots[cur_figure - 1][0][1], last = False)

    dots.append(list())

    dotslist_box.insert(END, "_______________________")

def add_seed_dot():
    global seed_dot

    try:
        x = float(x_seed_entry.get())
        y = float(y_seed_entry.get())
    except:
        show_error("Неверно введены координаты точки")
        return

    seed_dot = [x, y]

def get_fill_check_color(collor_fill):
    return (int(collor_fill[1:3], 16), int(collor_fill[3:5], 16), int(collor_fill[5:7], 16))

def fill_with_seed(dot_seed, color_fill, delay = False):
    color_fill = cu.Color(current_color[0]).hex
    color_fill_check = get_fill_check_color(color_fill)
    stack = list()
    stack.append(dot_seed)
    while (stack):
        dot_seed = stack.pop()

        x = dot_seed[0]
        y = dot_seed[1]
        
        image_canvas.put(color_fill, (x, y))
        tmp_x = x
        tmp_y = y
        # Заполнение текущей строки право до ребра или уже закрашенного пикселя
        x = x + 1

        while (image_canvas.get(x, y) != COLOR_LINE_CHECK 
                and image_canvas.get(x, y) != color_fill_check):
            image_canvas.put(color_fill, (x, y))
            x = x + 1

        x_right = x - 1
        # Заполнение текущей строки влево до ребра или уже закрашенного пикселя
        x = tmp_x - 1

        while (image_canvas.get(x, y) != COLOR_LINE_CHECK 
                and image_canvas.get(x, y) != color_fill_check):
            image_canvas.put(color_fill, (x, y))
            x = x - 1

        x_left = x + 1

        # Сканирование верхней строки
        x = x_left

        y = tmp_y + 1

        while (x <= x_right):
            flag = False

            # Поиск, есть ли в строке незакрашенный пиксель
            while (image_canvas.get(x, y) != COLOR_LINE_CHECK 
                    and image_canvas.get(x, y) != color_fill_check 
                    and x <= x_right):
                flag = True

                x = x + 1

            if (flag == True):
                if (x == x_right 
                        and image_canvas.get(x, y) != COLOR_LINE_CHECK
                        and image_canvas.get(x, y) != color_fill_check):
                    stack.append([x, y])
                else:
                    stack.append([x - 1, y])
            
                flag = False

            x_begin = x

            while ((image_canvas.get(x, y) == COLOR_LINE_CHECK 
                    or image_canvas.get(x, y) == color_fill_check) 
                    and x < x_right):
                x = x + 1

            if (x == x_begin):
                x = x + 1

        # Сканирование нижней строки
        x = x_left

        y = tmp_y - 1

        while (x <= x_right):
            flag = False    

            # Поиск, есть ли в строке незакрашенный пиксель
            while (image_canvas.get(x, y) != COLOR_LINE_CHECK 
                    and image_canvas.get(x, y) != color_fill_check 
                    and x <= x_right):
                flag = True

                x = x + 1

            if (flag == True):
                if (x == x_right 
                        and image_canvas.get(x, y) != COLOR_LINE_CHECK 
                        and image_canvas.get(x, y) != color_fill_check):
                    stack.append([x, y])
                else:
                    stack.append([x - 1, y])

                flag = False

            x_begin = x

            while ((image_canvas.get(x, y) == COLOR_LINE_CHECK 
                    or image_canvas.get(x, y) == color_fill_check) 
                    and x < x_right):
                x = x + 1

            if (x == x_begin):
                x = x + 1

        if (delay):
            sleep(0.001)
            canvas.update()

def reboot_prog():
    global dots
    global image_canvas
    global seed_dot

    canvas.delete("all")

    image_canvas = PhotoImage(width = CV_WIDE, height = CV_HEIGHT)
    canvas.create_image((CV_WIDE / 2, CV_HEIGHT / 2), image = image_canvas, state = "normal")

    image_canvas.put("#ffffff", to = (0, 0, CV_WIDE, CV_HEIGHT))

    canvas.grid(row = 0, column = 1, padx = 10, pady = 10)

    dots = [[]]
    seed_dot = []
    dotslist_box.delete(0, END)

def draw():

    cur_figure = len(dots) - 1

    if (len(dots[cur_figure]) != 0):
        show_error("Крайняя фигура не замкнута")
        return

    if (len(seed_dot) == 0):
        show_error("Затравочный пиксель не установлен")
        return

    if (option_filling.get() == 1):
        delay = True
    else:
        delay = False

    fill_with_seed(seed_dot, current_color, delay = delay)

window = Tk()
window['bg'] = 'lavender'
window.title('Lab_04')
window.geometry('1250x850')
window.minsize(1250, 850)
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

canvas = Canvas(window, bg = 'white', width = 800, height = 800)
canvas.grid(row = 0, column = 1, padx = 10, pady = 10)

image_canvas = PhotoImage(width = 800, height = 800)
canvas.create_image((400, 400), image = image_canvas, state = "normal")

canvas.bind("<1>", add_dot_click)
canvas.bind("<3>", add_seed_dot_click)

frame = Frame(window, bg = 'lavender', width = 300, height = 800)
frame.grid(row = 0, column = 0)
frame.columnconfigure(0, weight = 1)
frame.columnconfigure(1, weight = 1)
frame.rowconfigure(0, weight = 1)
frame.rowconfigure(1, weight = 1)
frame.rowconfigure(2, weight = 1)
frame.rowconfigure(3, weight = 1)
frame.rowconfigure(4, weight = 1)
frame.rowconfigure(5, weight = 1)
frame.rowconfigure(6, weight = 1)
frame.rowconfigure(7, weight = 1)
frame.rowconfigure(8, weight = 1)
frame.rowconfigure(9, weight = 1)
frame.rowconfigure(10, weight = 1)
frame.rowconfigure(11, weight = 1)
frame.rowconfigure(12, weight = 1)
frame.rowconfigure(13, weight = 1)
frame.rowconfigure(14, weight = 1)

add_label = Label(frame, text = 'Добавить точку', bg = 'lightgrey')
add_label.grid(padx = 5, pady = 10, row = 0, columnspan = 2)
x_label = Label(frame, text = 'X: ', bg = 'lightgrey')
x_label.grid(padx = 5, pady = 10, row = 1, column = 0)
y_label = Label(frame, text = 'Y: ', bg = 'lightgrey')
y_label.grid(padx = 5, pady = 10, row = 2, column = 0)

x_entry = Entry(frame)
x_entry.grid(padx = 5, pady = 10, row = 1, column = 1)
y_entry = Entry(frame)
y_entry.grid(padx = 5, pady = 10, row = 2, column = 1)

add_button = Button(frame, text = 'Добавить точку', command = read_dot)
add_button.grid(padx = 5, pady = 10, row = 3, columnspan = 2)
make_button = Button(frame, text = 'Замкнуть фигуру', command = make_figure)
make_button.grid(padx = 5, pady = 10, row = 4, columnspan = 2)
delete_button = Button(frame, text = 'Удалить крайнюю', command = del_dot)
delete_button.grid(padx = 5, pady = 10, row = 5, columnspan = 2)

point_list_label = Label(frame, text = 'Список точек')
point_list_label.grid(padx = 5, pady = 10, row = 6, columnspan = 2)
dotslist_box = Listbox(frame, bg = 'white', height = 15, width = 30)
dotslist_box.grid(padx = 5, pady = 10, row = 7, columnspan = 2)

x_seed_label = Label(frame, text = 'X: ')
x_seed_label.grid(padx = 5, pady = 10, row = 8, column = 0)
y_seed_label = Label(frame, text = 'Y: ')
y_seed_label.grid(padx = 5, pady = 10, row = 9, column = 0)

x_seed_entry = Entry(frame)
x_seed_entry.grid(padx = 5, pady = 10, row = 8, column = 1)
y_seed_entry = Entry(frame)
y_seed_entry.grid(padx = 5, pady = 10, row = 9, column = 1)

seed_button = Button(frame, text = 'Установить затравочный пиксель', command = add_seed_dot)
seed_button.grid(padx = 5, pady = 10, row = 10, columnspan=2)

type_label = Label(frame, text = 'Выбрать тип закраски')
type_label.grid(padx = 5, pady = 10, row = 11, columnspan = 2)

option_filling = IntVar()
option_filling.set(1)

draw_delay = Radiobutton(frame, text = "С задержкой", variable = option_filling, value = 1)
draw_delay.grid(padx = 5, pady = 10, row = 12, column = 0)
draw_without_delay = Radiobutton(frame, text = "Без задержки", variable = option_filling, value = 2)
draw_without_delay.grid(padx = 5, pady = 10, row = 12, column = 1)

fill_figure_btn = Button(frame, text = "Закрасить выбранную область", command = draw)
fill_figure_btn.grid(padx = 5, pady = 10, row = 13, column = 1)

clear_button = Button(frame, text = 'Очистить', command = reboot_prog)
clear_button.grid(row = 13, column = 0, padx = 5, pady = 10)

clr = Button(frame, text="Цвет для заполнения", command=lambda: choose_color())
clr.grid(padx = 5, pady = 1, row = 14, columnspan = 2)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()