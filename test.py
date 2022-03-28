import copy
from tkinter import messagebox, ttk, colorchooser
from tkinter import *
from math import *
import colorutils as cu
import numpy as np
import time

current_color = (0, 0, 0)
coord_center = [400, 400] 
m_board = 1
xy_history = []
xy_current = []
line_history = []

def save_state():
    global xy_history
    xy_history.append(copy.deepcopy(xy_current))

def to_coords(dot):
    x = (dot[0] - coord_center[0]) * m_board
    y = (- dot[1] + coord_center[1]) * m_board

    return [x, y]

def to_canva(dot):
    global m
    x = coord_center[0] + dot[0] / m_board
    y = coord_center[1] - dot[1] / m_board

    return [x, y]

def sign(diff):
    if diff < 0:
        return -1
    elif diff == 0:
        return 0
    else:
        return 1

def bresenham_int(p1, p2, color, step_count=False):
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]

    if (x2 - x1 == 0) and (y2 - y1 == 0):
        return [[x1, y1, color]]

    x = x1
    y = y1

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    s1 = sign(x2 - x1)
    s2 = sign(y2 - y1)

    swaped = 0
    if dy > dx:
        tmp = dx
        dx = dy
        dy = tmp
        swaped = 1

    e = 2 * dy - dx
    i = 1
    dots = []
    steps = 0

    while i <= dx + 1:
        dot = [x, y, color]
        dots.append(dot)

        x_buf = x
        y_buf = y

        while e >= 0:
            if swaped:
                x = x + s1
            else:
                y = y + s2

            e = e - 2 * dx

        if swaped:
            y = y + s2
        else:
            x = x + s1

        e = e + 2 * dy

        if step_count:
            if (x_buf != x) and (y_buf != y):
                steps += 1

        i += 1

    if step_count:
        return steps
    else:
        return dots


def bresenham_float(p1, p2, color, step_count=False):
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]

    if x2 - x1 == 0 and y2 - y1 == 0:
        return [[x1, y1, color]]

    x = x1
    y = y1

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    s1 = sign(x2 - x1)
    s2 = sign(y2 - y1)

    if dy > dx:
        tmp = dx
        dx = dy
        dy = tmp
        swaped = 1
    else:
        swaped = 0

    m = dy / dx
    e = m - 0.5
    i = 1

    dots = []
    steps = 0

    while i <= dx + 1:
        dot = [x, y, color]
        dots.append(dot)

        x_buf = x
        y_buf = y

        while e >= 0:
            if swaped:
                x = x + s1
            else:
                y = y + s2

            e = e - 1

        if swaped:
            y = y + s2
        else:
            x = x + s1

        e = e + m

        if step_count:
            if not((x_buf == x and y_buf != y) or
                    (x_buf != x and y_buf == y)):
                steps += 1

        i += 1

    if step_count:
        return steps
    else:
        return dots


def choose_color(color, intens):
    return color + (intens, intens, intens)


def bresenham_smooth(p1, p2, color, step_count=False):
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]

    if (x2 - x1 == 0) and (y2 - y1 == 0):
        return [[x1, y1, color]]

    x = x1
    y = y1

    dx = abs(x2 - x1)
    dy = abs(y2 - y1)

    s1 = sign(x2 - x1)
    s2 = sign(y2 - y1)

    swaped = 0
    if dy > dx:
        tmp = dx
        dx = dy
        dy = tmp
        swaped = 1

    intens = 255

    m = dy / dx
    e = intens / 2

    m *= intens
    w = intens - m

    dots = [[x, y, choose_color(color, round(e))]]

    i = 1

    steps = 0

    while i <= dx:
        x_buf = x
        y_buf = y

        if e < w:
            if swaped:
                y += s2
            else:
                x += s1
            e += m
        else:
            x += s1
            y += s2

            e -= w

        dot = [x, y, choose_color(color, round(e))]

        dots.append(dot)

        if step_count:
            if not ((x_buf == x and y_buf != y) or
                    (x_buf != x and y_buf == y)):
                steps += 1

        i += 1

    if step_count:
        return steps
    else:
        return dots


def cda_method(p1, p2, color, step_count = False):
    x1, y1 = p1[0], p1[1]
    x2, y2 = p2[0], p2[1]

    if (x2 - x1 == 0) and (y2 - y1 == 0):
        return [[x1, y1, color]]

    dx = x2 - x1
    dy = y2 - y1

    if abs(dx) >= abs(dy):
        l = abs(dx)
    else:
        l = abs(dy)

    dx /= l
    dy /= l

    x = round(x1)
    y = round(y1)

    dots = [[round(x), round(y), color]]

    i = 1

    steps = 0

    while i < l:

        x += dx
        y += dy

        dot = [round(x), round(y), color]

        dots.append(dot)

        if step_count:
            if not((round(x + dx) == round(x) and
                        round(y + dy) != round(y)) or
                        (round(x + dx) != round(x) and
                        round(y + dy) == round(y))):
                steps += 1

        i += 1

    if step_count:
        return steps
    else:
        return dots


def wu(p1, p2, color, step_count=False):
    x1 = p1[0]
    y1 = p1[1]
    x2 = p2[0]
    y2 = p2[1]

    if (x2 - x1 == 0) and (y2 - y1 == 0):
        return [[x1, y1, color]]

    dx = x2 - x1
    dy = y2 - y1

    m = 1
    step = 1
    intens = 255

    dots = []

    steps = 0

    if fabs(dy) > fabs(dx):
        if dy != 0:
            m = dx / dy
        m1 = m

        if y1 > y2:
            m1 *= -1
            step *= -1

        y_end = round(y2) - 1 if (dy < dx) else (round(y2) + 1)

        for y_cur in range(round(y1), y_end, step):
            d1 = x1 - floor(x1)
            d2 = 1 - d1

            dot1 = [int(x1) + 1, y_cur, choose_color(color, round(fabs(d2) * intens))]

            dot2 = [int(x1), y_cur, choose_color(color, round(fabs(d1) * intens))]

            if step_count and y_cur < y2:
                if int(x1) != int(x1 + m):
                    steps += 1

            dots.append(dot1)
            dots.append(dot2)

            x1 += m1

    else:
        if dx != 0:
            m = dy / dx

        m1 = m

        if x1 > x2:
            step *= -1
            m1 *= -1

        x_end = round(x2) - 1 if (dy > dx) else (round(x2) + 1)

        for x_cur in range(round(x1), x_end, step):
            d1 = y1 - floor(y1)
            d2 = 1 - d1

            dot1 = [x_cur, int(y1) + 1, choose_color(color, round(fabs(d2) * intens))]
            dot2 = [x_cur, int(y1), choose_color(color, round(fabs(d1) * intens))]

            if step_count and x_cur < x2:
                if int(y1) != int(y1 + m):
                    steps += 1

            dots.append(dot1)
            dots.append(dot2)

            y1 += m1

    if step_count:
        return steps
    else:
        return dots

def change_bg_color():
    global canvas_bg
    canvas_bg = colorchooser.askcolor()
    canvas_win.configure(bg=cu.Color(canvas_bg[1]))

def choose_line_color():
    global current_color
    current_color = colorchooser.askcolor()

def parse_line(option):
    try:
        x1 = int(x1_entry.get())
        y1 = int(y1_entry.get())
        x2 = int(x2_entry.get())
        y2 = int(y2_entry.get())
    except ValueError:
        messagebox.showerror("Ошибка", "Неверно введены координаты")
        return
    p1 = [x1, y1]
    p2 = [x2, y2]
    canvas_win.delete('line')
    parse_methods(p1, p2, option)

def parse_methods(p1, p2, option, draw=True):
    color = cu.Color(current_color[0])
    if option == 0:
        dots = bresenham_int(p1, p2, color)
        if draw:
            draw_line(dots)

    elif option == 1:
        dots = bresenham_float(p1, p2, color)
        if draw:
            draw_line(dots)

    elif option == 2:
            dots = bresenham_smooth(p1, p2, color)
            if draw:
                draw_line(dots)

    elif option == 3:
        dots = cda_method(p1, p2, color)
        if draw:
            draw_line(dots)

    elif option == 4:
        dots = wu(p1, p2, color)
        if draw:
            draw_line(dots)
    else:
        messagebox.showerror("Ошибка", "Неизвестный алгоритм")

def draw_line(dots):
    global xy_history, line_history
    for dot in dots:
        tmp = to_canva(dot[0:2])
        point = [tmp[0], tmp[1], dot[2]]
        canvas_win.create_line(point[0], point[1], point[0] + 1, point[1], fill=point[2].hex, tag='line', width = 2)
    xy_history.append(xy_current)
    line_history.append(dots)
    canvas_win.delete('dot1', 'dot2')

def clean_canvas():
    line_history.clear()
    canvas_win.delete('line', 'dot1', 'dot2')

def draw_without_history(dots):
    for dot in dots:
        tmp = to_canva(dot[0:2])
        point = [tmp[0], tmp[1], dot[2]]
        canvas_win.create_line(point[0], point[1], point[0] + 1, point[1], fill=point[2].hex, tag='line')

def draw_all_lines(array_dots, history_param):
    for dots in array_dots:
        if history_param:
            draw_without_history(dots)
        else:
            draw_line(dots)

def change_size(plus_or_minus):
    global m_board, xy_current
    save_state()
    canvas_win.delete('coord', 'line')

    if plus_or_minus == 0:
        m_board *= 2
        xy_current = [xy_current[i] * 2 for i in range(len(xy_current))]

    else:
        m_board /= 2
        xy_current = [xy_current[i] / 2 for i in range(len(xy_current))]

    xy_history.append(xy_current)
    draw_all_lines(line_history, 1)

def build_spectra_1():
    try:
        line_len = float(length_entry.get())
        angle_spin = float(angle_entry.get())
    except ValueError:
        messagebox.showerror("Ошибка", "Неверно введены параметры построения")
        return

    if line_len <= 0:
        messagebox.showerror("Ошибка", "Длина должна быть неотрицательна")
        return

    if angle_spin <= 0:
        messagebox.showerror("Ошибка", "Угол должен быть неотрицателен")
        return

    p1 = [0, 0]
    spin = 0
    canvas_win.delete('line')
    while spin <= 2 * pi:
        x2 = p1[0] + cos(spin) * line_len
        y2 = p1[1] + sin(spin) * line_len

        p2 = [x2, y2]
        parse_methods(p1, p2, method_combo.current())
        spin += radians(angle_spin)

window = Tk()
window['bg'] = 'lavender'
window.geometry("1250x850")
window.title("Лабораторная работа #3")
window.rowconfigure(0, weight = 1)
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)

canvas_win = Canvas(window, width = 800, height= 800, bg = 'white')
canvas_win.grid(row = 0, column=1)
canvas_win.create_line(0, 400, 800, 400, tag = 'ox', arrow = 'last')
canvas_win.create_line(400, 0, 400, 800, tag = 'oy', arrow = 'first')

frame = Frame(window, width = 400, height=800, bg = 'lavender')
frame.grid(padx = 10,pady = 10, row = 0, column = 0)
frame.columnconfigure(0, weight = 1)
frame.columnconfigure(1, weight = 1)
frame.columnconfigure(2, weight = 1)
frame.columnconfigure(3, weight = 1)
frame.rowconfigure(0, weight = 1)
frame.rowconfigure(1, weight = 1)
frame.rowconfigure(2, weight = 1)
frame.rowconfigure(3, weight = 1)
frame.rowconfigure(4, weight = 1)
frame.rowconfigure(5, weight = 1)
frame.rowconfigure(6, weight = 1)
frame.rowconfigure(7, weight = 1)
frame.rowconfigure(8, weight = 1)

center_lbl = Label(frame, text="Координаты отрезков", bg='lavender')
center_lbl.grid(padx = 10,pady = 10, row = 0, columnspan = 4)
x1_lbl = Label(frame, text="X1", bg = 'lavender')
x1_lbl.grid(padx = 10,pady = 10, row = 1, column=0)
y1_lbl = Label(frame, text="Y1", bg = 'lavender')
y1_lbl.grid(padx = 10,pady = 10, row = 1, column=2)
x1_entry = Entry(frame, bg='white', borderwidth=0)
x1_entry.grid(padx = 10,pady = 10, row = 1, column=1)
y1_entry = Entry(frame, bg='white', borderwidth=0)
y1_entry.grid(padx = 10,pady = 10, row = 1, column=3)

x1_entry.insert(END, 0)
y1_entry.insert(END, 0)

x2_lbl = Label(frame, text="X2", bg = 'lavender')
x2_lbl.grid(padx = 10,pady = 10, row = 2, column=0)
y2_lbl = Label(frame, text="Y2", bg = 'lavender')
y2_lbl.grid(padx = 10,pady = 10, row = 2, column=2)
x2_entry = Entry(frame, bg='white',borderwidth=0)
x2_entry.grid(padx = 10,pady = 10, row = 2, column= 1)
y2_entry = Entry(frame, bg='white',borderwidth=0)
y2_entry.grid(padx = 10,pady = 10, row = 2, column= 3)
x2_entry.insert(END, 250)
y2_entry.insert(END, 250)

method_lbl = Label(frame, text="Алгоритм", bg='lavender')
method_lbl.grid(padx = 10,pady = 10, row = 3, columnspan= 2)
method_combo = ttk.Combobox(frame, values=["Брезенхем (целые)", "Брезенхем (вещ)", "Брезенхем (устран. ступ.)",
                                         "ЦДА", "Ву"], state='readonly')
method_combo.grid(padx = 10,pady = 10, row = 3, column= 2, columnspan= 2)
method_combo.current(0)  

# Кнопки
bld_button = Button(frame, text="Построить отрезок", borderwidth=0, command=lambda: parse_line(method_combo.current()))
bld_button.grid(padx = 10,pady = 10, row = 4, columnspan=4)             
    
clr_button = Button(frame, text="Цвет отрезка", borderwidth=0, command=lambda: choose_line_color())                              
clr_button.grid(padx = 10,pady = 10, row = 5, columnspan = 2)             
bgc_button = Button(frame, text="Цвет фона", borderwidth=0, command=lambda: change_bg_color())
bgc_button.grid(padx = 10,pady = 10, row = 5, column=2, columnspan=2) 

length_label = Label(frame, text = 'Длина', bg = 'lavender', width = 10)
length_label.grid(row = 6, column = 0, padx = 10, pady = 10)
length_entry = Entry(frame, width = 10)
length_entry.grid(row = 6, column = 1, padx = 10, pady = 10)
length_entry.insert(END, 100)
angle_label = Label(frame, text = 'Угол', bg = 'lavender',width= 10)
angle_label.grid(row = 6, column = 2 , padx = 10, pady = 10)
angle_entry = Entry(frame, width = 10)
angle_entry.grid(row = 6, column = 3, padx = 10, pady = 10)
angle_entry.insert(END, 10)

sp1_button = Button(frame, text="Построит пучок",borderwidth=0, command=lambda: build_spectra_1())
sp1_button.grid(padx = 10,pady = 10, row = 7, columnspan=4)     

bgn_button = Button(frame, text="Сброс", borderwidth=0, command=lambda: clean_canvas())
bgn_button.grid(padx = 10,pady = 10, row = 8, column=2, columnspan=2)                       
pls_button = Button(frame, text="+", borderwidth=0, command=lambda: change_size(1))
pls_button.grid(padx = 10,pady = 10, row = 8, column=1)
mns_button = Button(frame, text="-", borderwidth=0, command=lambda: change_size(0))
mns_button.grid(padx = 10,pady = 10, row = 8, column=0)                    

window.mainloop()