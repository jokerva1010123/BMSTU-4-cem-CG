from tkinter import *
import tkinter.messagebox as box
from tkinter import colorchooser
from math import *
import copy
import numpy as np
import matplotlib.pyplot as plt
from time import time, sleep
import colorutils as cu

dots = [[]]
sides_list = [[]]

task = '''Данная программа реализует и исследует алгоритмы 
растрового заполнения сплошных областей.'''

def show_info(str):
    box.showinfo("Информация", str)
    return

def show_error(str):
    box.showerror("Error", str)
    return

CV_WIDE = 900
CV_HEIGHT = 900
CV_COLOR = "#ffffff"

TEMP_SIDE_COLOR_CHECK = (255, 0, 255) # purple
TEMP_SIDE_COLOR = "#ff00ff"

COLOR_LINE = "black" #(0, 0, 0) # black\\

current_color = (0, 0, 0)

def clear_canvas():
    canvas.delete("all")


def draw_dot(x, y, color):
    image_canvas.put(color, (x, y))
    
def choose_color():
    global current_color
    current_color = colorchooser.askcolor()

def sign(difference):
    if (difference < 0):
        return -1
    elif (difference == 0):
        return 0
    else:
        return 1


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


def add_dot(x, y, last = True):
    cur_figure = len(dots) - 1
    dots[cur_figure].append([x, y])

    cur_dot = len(dots[cur_figure]) - 1

    if (last):
        dotslist_box.insert(END, "%d. (%4d;%4d)" %(cur_dot + 1, x, y))

    if (len(dots[cur_figure]) > 1):
        sides_list[cur_figure].append([dots[cur_figure][cur_dot - 1], dots[cur_figure][cur_dot]])

        bresenham_int(dots[cur_figure][cur_dot - 1], dots[cur_figure][cur_dot], COLOR_LINE)
        

def del_dot():
    cur_figure = len(dots) - 1
    cur_dot = len(dots[cur_figure]) - 1

    if (len(dots[cur_figure]) == 0):
        show_error("Нет незамкнутой фигиры")
        return

    if (len(dots[cur_figure]) > 1):
        sides_list[cur_figure].pop()
        bresenham_int(dots[cur_figure][cur_dot - 1], dots[cur_figure][cur_dot], "white")

    # Find index for a table

    index = 0

    for i in range(cur_figure + 1):
        index += (len(dots[i]))

    #index += cur_figure


    dotslist_box.delete(index - 1, END)

    dots[cur_figure].pop(len(dots[cur_figure]) - 1)


def make_figure():
    cur_figure = len(dots)
    cur_dot = len(dots[cur_figure - 1])

    if (cur_dot < 3):
        show_error("Недостаточно точек, чтобы замкнуть фигуру")

    add_dot(dots[cur_figure - 1][0][0], dots[cur_figure - 1][0][1], last = False)

    dots.append(list())
    sides_list.append(list())

    dotslist_box.insert(END, "_______________________")


def line_koefs(x1, y1, x2, y2):
    a = y1 - y2
    b = x2 - x1
    c = x1*y2 - x2*y1

    return a, b, c


def solve_lines_intersection(a1, b1, c1, a2, b2, c2):
    opr = a1*b2 - a2*b1
    opr1 = (-c1)*b2 - b1*(-c2)
    opr2 = a1*(-c2) - (-c1)*a2

    x = opr1 / opr
    y = opr2 / opr

    return x, y


def round_side(dot1, dot2):
    if (dot1[1] == dot2[1]):
        return

    a_side, b_side, c_side = line_koefs(dot1[0], dot1[1], dot2[0], dot2[1])

    if (dot1[1] > dot2[1]):
        y_max = dot1[1]
        y_min = dot2[1]
        x = dot2[0]
    else:
        y_max = dot2[1]
        y_min = dot1[1]
        x = dot1[0]

    y = y_min

    while (y < y_max):
        a_scan_line, b_scan_line, c_scan_line = line_koefs(x, y, x + 1, y)

        x_intersec, y_intersec = solve_lines_intersection(a_side, b_side, c_side, a_scan_line, b_scan_line, c_scan_line)  

        if (image_canvas.get(int(x_intersec) + 1, y) != TEMP_SIDE_COLOR_CHECK):
            image_canvas.put(TEMP_SIDE_COLOR, (int(x_intersec) + 1, y))
        else:
            image_canvas.put(TEMP_SIDE_COLOR, (int(x_intersec) + 2, y))

        y += 1

        canvas.update()


def round_figure():
    for figure in range(len(sides_list)):
        sides_num = len(sides_list[figure]) - 1

        for side in range(sides_num + 1):
            round_side(sides_list[figure][side][0], sides_list[figure][side][1])


def get_edges(dots):
    x_max = 0
    x_min = CV_WIDE

    y_max = CV_HEIGHT
    y_min = 0

    for figure in dots:
        for dot in figure:
            if (dot[0] > x_max):
                x_max = dot[0]
            
            if (dot[0] < x_min):
                x_min = dot[0]

            if (dot[1] < y_max):
                y_max = dot[1]
            
            if (dot[1] > y_min):
                y_min = dot[1]

    block_edges = (x_min, y_min, x_max, y_max)

    return block_edges


def draw():

    cur_figure = len(dots) - 1

    if (len(dots[cur_figure]) != 0):
        show_error("Крайняя фигура не замкнута")
        return

    block_edges = get_edges(dots)

    if (option_filling.get() == 1):
        delay = True
    else:
        delay = False

    fill_with_sides_and_flag(sides_list, block_edges, current_color, delay)


def fill_with_sides_and_flag(sides_list, block_edges, color_fill, delay = False):
    round_figure()
    canvas.update()

    x_max = block_edges[2]
    x_min = block_edges[0]

    y_max = block_edges[3]
    y_min = block_edges[1]    

    for y in range(y_min, y_max - 1, -1):
        flag = False

        for x in range(x_min, x_max + 2):

            if (image_canvas.get(x, y) == TEMP_SIDE_COLOR_CHECK):
                flag = not flag

            if flag:
                color = cu.Color(current_color[0])
                image_canvas.put(color.hex, (x, y))
            else:
                image_canvas.put(CV_COLOR, (x, y))

        if delay:
            canvas.update()
            sleep(0.01 * 1)


def reboot_prog():
    global dots
    global sides_list
    global image_canvas

    canvas.delete("all")

    image_canvas = PhotoImage(width = CV_WIDE, height = CV_HEIGHT)
    canvas.create_image((CV_WIDE / 2, CV_HEIGHT / 2), image = image_canvas, state = "normal")

    canvas.grid(row = 0, column = 1)

    dots = [[]]
    sides_list = [[]]
    dotslist_box.delete(0, END)

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

type_label = Label(frame, text = 'Выбрать тип закраски')
type_label.grid(padx = 5, pady = 10, row = 8, columnspan = 2)

option_filling = IntVar()
option_filling.set(1)

draw_delay = Radiobutton(frame, text = "С задержкой", variable = option_filling, value = 1)
draw_delay.grid(padx = 5, pady = 10, row = 9, column = 0)
draw_without_delay = Radiobutton(frame, text = "Без задержки", variable = option_filling, value = 2)
draw_without_delay.grid(padx = 5, pady = 10, row = 9, column = 1)

fill_figure_btn = Button(frame, text = "Закрасить выбранную область", command = draw)
fill_figure_btn.grid(padx = 5, pady = 10, row = 10, column = 1)

clear_button = Button(frame, text = 'Очистить', command = reboot_prog)
clear_button.grid(row = 10, column = 0, padx = 5, pady = 10)

clr = Button(frame, text="Цвет для заполнения", command=lambda: choose_color())
clr.grid(padx = 5, pady = 1, row = 11, columnspan = 2)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()