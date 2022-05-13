from tkinter import *
from tkinter import messagebox, colorchooser
from math import *
import colorutils as cu

X_MIN = 0
X_MAX = 1
Y_MIN = 2
Y_MAX = 3

X_DOT = 0
Y_DOT = 1

task = '''Реализовать отсечение отрезка регулярным отсекателем по методу: Сазерленда-Коэна'''

lines = [[]]
is_set_rect = False
rect = [-1, -1, -1, -1]
color_rec = ((255, 0, 0), 0)
color_line = ((0, 255, 0), 0)
color_result = ((0, 0, 255), 0)

def change_color_rec():
    global current_color
    color_rec = colorchooser.askcolor()

def change_color_line():
    global current_color
    color_line = colorchooser.askcolor()

def change_color_result():
    global current_color
    color_result = colorchooser.askcolor()

def add_line_click(event):    
    x = event.x
    y = event.y

    cur_line = len(lines) - 1

    if (len(lines[cur_line]) == 0):
        lines[cur_line].append([x, y])
    else:
        lines[cur_line].append([x, y])
        lines[cur_line].append(color_line)
        lines.append(list())

        x1 = lines[cur_line][0][0]
        y1 = lines[cur_line][0][1]

        x2 = lines[cur_line][1][0]
        y2 = lines[cur_line][1][1]

        canvas.create_line(x1, y1, x2, y2, fill = cu.Color(color_line[0]).hex)

def add_rect_click(event):
    global rect
    global is_set_rect

    if (is_set_rect == False):
        rect[X_MIN] = event.x
        rect[Y_MAX] = event.y

        is_set_rect = True
    else:
        x_first = rect[X_MIN]
        y_first = rect[Y_MAX]

        x = event.x
        y = event.y

        canvas.delete("all")
        canvas.create_rectangle(x_first, y_first, x, y, outline = cu.Color(color_rec[0]).hex)

        rect[X_MAX] = x
        rect[Y_MIN] = y

        draw_lines()

def add_rect_click1(event):
    global is_set_rect

    is_set_rect = False

def add_line():
    global lines

    try:
        x1 = int(x_start_line_entry.get())
        y1 = int(y_start_line_entry.get())
        x2 = int(x_end_line_entry.get())
        y2 = int(y_end_line_entry.get())
    except:
        messagebox.showinfo("Ошибка", "Неверно введены координаты")
        return

    cur_line = len(lines) - 1

    lines[cur_line].append([x1, y1])
    lines[cur_line].append([x2, y2])
    lines[cur_line].append(color_line)

    lines.append(list())
    
    canvas.create_line(x1, y1, x2, y2, fill = cu.Color(color_line[0]).hex)

def draw_lines():
    for line in lines:
        if (len(line) != 0):
            x1 = line[0][0]
            y1 = line[0][1]

            x2 = line[1][0]
            y2 = line[1][1]

            canvas.create_line(x1, y1, x2, y2, fill = cu.Color(line[2][0]).hex)

def add_rect():
    global rect

    try:
        x_min = int(xleft_cutter_entry.get())
        y_max = int(yleft_cutter_entry.get())
        x_max = int(xright_cutter_entry.get())
        y_min = int(yright_cutter_entry.get())
    except:
        messagebox.showinfo("Ошибка", "Неверно введены координаты")
        return

    canvas.delete("all")
    canvas.create_rectangle(x_min, y_max, x_max, y_min, outline = cu.Color(color_rec[0]).hex)

    rect = [x_min, x_max, y_min, y_max]

    draw_lines()

def get_dot_bits(rect, dot):
    bits = 0b0000

    if (dot[X_DOT] < rect[X_MIN]):
        bits += 0b0001

    if (dot[X_DOT] > rect[X_MAX]):
        bits += 0b0010
    
    if (dot[Y_DOT] > rect[Y_MIN]): # из-за экранной системы координат поменены
        bits += 0b0100
        
    if (dot[Y_DOT] < rect[Y_MAX]): # из-за экранной системы координат поменены
        bits += 0b1000

    return bits


def check_visible(dot1_bits, dot2_bits):
    vision = 0 # частично видимый

    if (dot1_bits == 0 and dot2_bits == 0):
        vision = 1 # видим
    elif (dot1_bits & dot2_bits):
        vision = -1 # не видим

    return vision


def get_bit(dot_bits, i):
    return (dot_bits >> i) & 1

def are_bits_equal(dot1_bits, dot2_bits, i):
    if get_bit(dot1_bits, i) == get_bit(dot2_bits, i):
        return True

    return False

def method_sazerland_kohen(rect, line):
    dot1 = [line[0][X_DOT], line[0][Y_DOT]]
    dot2 = [line[1][X_DOT], line[1][Y_DOT]]

    fl = 0

    if (dot1[X_DOT] == dot2[X_DOT]):
        fl = -1 # вертикальный
    else:
        m = (dot2[Y_DOT] - dot1[Y_DOT]) / (dot2[X_DOT] - dot1[X_DOT])

        if (m == 0):
            fl = 1 # горизонтальный

    for i in range(4):
        dot1_bits = get_dot_bits(rect, dot1)
        dot2_bits = get_dot_bits(rect, dot2)

        vision = check_visible(dot1_bits, dot2_bits)

        if (vision == -1):
            return # выйти и не рисовать
        elif (vision == 1):
            break # нарисовать и выйти

        if (are_bits_equal(dot1_bits, dot2_bits, i)):
            continue

        if get_bit(dot1_bits, i) == 0:
            tmp = dot1
            dot1 = dot2
            dot2 = tmp

        if (fl != -1):
            if (i < 2):
                dot1[Y_DOT] = m * (rect[i] - dot1[X_DOT]) + dot1[Y_DOT]
                dot1[X_DOT] = rect[i]
                continue
            else:
                dot1[X_DOT] = (1 / m) * (rect[i] - dot1[Y_DOT]) + dot1[X_DOT]

        dot1[Y_DOT] = rect[i]

    canvas.create_line(dot1[X_DOT], dot1[Y_DOT], dot2[X_DOT], dot2[Y_DOT], fill = cu.Color(color_result[0]).hex)

def cut_area():
    global rect
    if (rect[0] == -1):
        messagebox.showinfo("Ошибка", "Не задан отсекатель")
    rect = [min(rect[0], rect[1]), max(rect[0], rect[1]), max(rect[2], rect[3]), min(rect[2], rect[3])]
    canvas.create_rectangle(rect[X_MIN] + 1, rect[Y_MAX] + 1, rect[X_MAX] - 1, rect[Y_MIN] - 1, fill = "white", outline = "white")
    for line in lines:
        if (line):
            method_sazerland_kohen(rect, line)

def reboot_prog():
    global lines
    global rect

    canvas.delete("all")

    lines = [[]]
    rect = [-1, -1, -1, -1]

window = Tk()
window['bg'] = 'lavender'
window.title('Lab_07')
window.geometry('1250x850')
window.minsize(1250, 850)
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

canvas = Canvas(window, bg = 'white', width = 800, height = 800)
canvas.grid(row = 0, column = 1, padx = 10, pady = 10)

canvas.bind("<3>", add_line_click)
canvas.bind("<1>", add_rect_click1)
canvas.bind('<B1-Motion>', add_rect_click)

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

cutter_text = Label(frame, text = "Координаты отсекателя", bg = 'lavender')
cutter_text.grid(row = 0, columnspan = 2, padx = 10, pady = 10)

xleft_cutter_text = Label(frame, text = "Левый верхний x: ", bg = 'lavender')
xleft_cutter_text.grid(row = 1, column = 0, padx = 10, pady = 10)

xleft_cutter_entry = Entry(frame)
xleft_cutter_entry.grid(row = 1, column = 1, padx = 10, pady = 10)

yleft_cutter_text = Label(frame, text = "Левый верхний y: ", bg = 'lavender')
yleft_cutter_text.grid(row = 2, column = 0, padx = 10, pady = 10)

yleft_cutter_entry = Entry(frame)
yleft_cutter_entry.grid(row = 2, column = 1, padx = 10, pady = 10)

xright_cutter_text = Label(frame, text = "Правый нижний x: ", bg = 'lavender')
xright_cutter_text.grid(row = 3, column = 0, padx = 10, pady = 10)

xright_cutter_entry = Entry(frame)
xright_cutter_entry.grid(row = 3, column = 1, padx = 10, pady = 10)

yright_cutter_text = Label(frame, text = "Правый нижний y: ", bg = 'lavender')
yright_cutter_text.grid(row = 4, column = 0, padx = 10, pady = 10)

yright_cutter_entry = Entry(frame)
yright_cutter_entry.grid(row = 4, column = 1, padx = 10, pady = 10)

add_cutter_btn = Button(frame, text = "Нарисовать отсекатель", command = lambda: add_rect())
add_cutter_btn.grid(row = 5, columnspan = 2, padx = 10, pady = 10)

addline_text = Label(frame, text = "Добавить отрезок", bg = 'lavender')
addline_text.grid(row = 6, columnspan = 2, padx = 10, pady = 10)

x_start_line_text = Label(frame, text = "Начало x: ", bg = 'lavender')
x_start_line_text.grid(row = 7, column = 0, padx = 10, pady = 10)

x_start_line_entry = Entry(frame)
x_start_line_entry.grid(row = 7, column = 1, padx = 10, pady = 10)

y_start_line_text = Label(frame, text = "Начало y: ", bg = 'lavender')
y_start_line_text.grid(row = 8, column = 0, padx = 10, pady = 10)

y_start_line_entry = Entry(frame)
y_start_line_entry.grid(row = 8, column = 1, padx = 10, pady = 10)

x_end_line_text = Label(frame, text = "Конец x: ", bg = 'lavender')
x_end_line_text.grid(row = 9, column = 0, padx = 10, pady = 10)

x_end_line_entry = Entry(frame)
x_end_line_entry.grid(row = 9, column = 1, padx = 10, pady = 10)

y_end_line_text = Label(frame, text = "Конец y: ", bg = 'lavender')
y_end_line_text.grid(row = 10, column = 0, padx = 10, pady = 10)

y_end_line_entry = Entry(frame)
y_end_line_entry.grid(row = 10, column = 1, padx = 10, pady = 10)

add_line_btn = Button(frame, text = "Нарисовать отрезок", command = lambda: add_line())
add_line_btn.grid(row = 11, columnspan = 2, padx = 10, pady = 10)

changecolor_rec = Button(frame, text = 'цвет отсекателя', command = lambda: change_color_rec())
changecolor_rec.grid(row = 12, column = 0, padx = 10, pady = 10)
changecolor_line = Button(frame, text = 'цвет отрезка', command = lambda: change_color_line())
changecolor_line.grid(row = 12, column = 1, padx = 10, pady = 10)
changecolor_result = Button(frame, text = 'цвет результата', command = lambda: change_color_result())
changecolor_result.grid(row = 13, columnspan = 2, padx = 10, pady = 10)

cut_btn = Button(frame, text = "Отсечь", command = lambda: cut_area())
cut_btn.grid(row = 14, column = 0, padx = 10, pady = 10)

clear_btn = Button(frame, text = "Очистить экран", command = lambda: reboot_prog())
clear_btn.grid(row = 14, column = 1, padx = 10, pady = 10)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()