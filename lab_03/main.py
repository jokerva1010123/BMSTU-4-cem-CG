from tkinter import *
from tkinter import colorchooser
import tkinter.ttk as ttk
import tkinter.messagebox as box
import colorutils as cu
from math import *

task = "Алгоритмы построения отрезков.\n\n" \
       "Реализовать возможность построения " \
       "отрезков методами Брезенхема, Ву, ЦДА, " \
       "построение пучка отрезков и " \
       "сравнение времени и ступенчатости."

current_color = (0, 0, 0)
coord_center = [400, 400] 
scale = 1
points = []
points_spectra = []
points_check = []

def to_coords(dot):
    global scale
    x = (dot[0] - coord_center[0]) * scale
    y = (- dot[1] + coord_center[1]) * scale

    return [x, y]

def to_canva(dot):
    global scale
    x = coord_center[0] + dot[0] / scale
    y = coord_center[1] - dot[1] / scale

    return [x, y]

def show_info(str):
    box.showinfo("Информация", str)
    return

def show_error(str):
    box.showerror("Error", str)
    return

def change_bg_color():
    canvas_bg = colorchooser.askcolor()
    canvas.configure(bg=cu.Color(canvas_bg[1]))

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

        i += 1

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


        i += 1

    
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

        i += 1
    
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


            dots.append(dot1)
            dots.append(dot2)

            y1 += m1

    
    return dots


def draw(dots):
    for index in range(0, len(dots)):
        tmp1 = to_canva(dots[index][:2])
        canvas.create_line(tmp1[0], tmp1[1], tmp1[0]+1, tmp1[1]+1, fill = dots[index][2].hex, tag = 'line', width = 2)

def choose_line_color():
    global current_color, points, points_spectra
    current_color = colorchooser.askcolor()
    if points:
        for x in points:
            x[2] = cu.Color(current_color[0])
        canvas.delete('line')
        draw(points)
        return 
    if len(points_spectra):
        for x in points_spectra:
            x[2] = cu.Color(current_color[0])
        canvas.delete('line')
        draw(points_spectra)
        return 
    if (len(points_check)):
        for x in points_check:
            x[2] = cu.Color(current_color[0])
        canvas.delete('line')
        canvas.create_line(to_canva(points_check[0]), to_canva(points_check[-1]), fill = 'black', tag = 'line')
        draw(points_check)
    

def draw_line():
    global points, points_spectra, points_check
    points_check = []
    points_spectra = []
    try:
        x1 = int(x1_entry.get())
        y1 = int(y1_entry.get())
        x2 = int(x2_entry.get())
        y2 = int(y2_entry.get())
    except ValueError:
        show_error("Неверно введены координаты")
        return -1 
    p1 = [x1, y1]
    p2 = [x2, y2]
    color = cu.Color(current_color[0])
    option = method_combo.current()
    if option == 0:
        points = bresenham_int(p1, p2, color)
    elif option == 1:
        points = bresenham_float(p1, p2, color)
    elif option == 2:
            points = bresenham_smooth(p1, p2, color)
    elif option == 3:
        points = cda_method(p1, p2, color)
    elif option == 4:
        points = wu(p1, p2, color)
    else:
        show_error("Неизвестный алгоритм")
        return -1
    canvas.delete('line')
    draw(points)
    return 0

def draw_spectra(p1, p2):
    global points_spectra
    color = cu.Color(current_color[0])
    option = method_combo.current()
    if option == 0:
        points_spectra += bresenham_int(p1, p2, color)
    elif option == 1:
        points_spectra += bresenham_float(p1, p2, color)
    elif option == 2:
            points_spectra += bresenham_smooth(p1, p2, color)
    elif option == 3:
        points_spectra += cda_method(p1, p2, color)
    elif option == 4:
        points_spectra += wu(p1, p2, color)
    else:
        show_error("Неизвестный алгоритм")
        return -1

def spectra():
    global points_spectra, points, points_check
    points_check = []
    points_spectra = []
    points = []
    try:
        line_len = float(length_entry.get())
        angle_spin = float(angle_entry.get())
    except ValueError:
        show_error("Неверно введены параметры построения")
        return -1
    if line_len <= 0:
        show_error("Длина должна быть неотрицательна")
        return -1

    if angle_spin <= 0:
        show_error("Угол должен быть неотрицателен")
        return -1

    p1 = [0, 0]
    spin = 0

    while spin <= 2 * pi:
        x2 = p1[0] + cos(spin) * line_len
        y2 = p1[1] + sin(spin) * line_len

        p2 = [x2, y2]

        draw_spectra(p1, p2)
        spin += radians(angle_spin)
    canvas.delete('line')
    draw(points_spectra)

def change_size(type):
    global scale, points, points_spectra
    tmp = []    
    if type == '-':
        scale *= 2
    else:
        scale /= 2
    if len(points):
        canvas.delete('line')
        draw(points)
        return
    if len(points_spectra):
        canvas.delete('line')
        draw(points_spectra)
        return
    if (len(points_check)):
        canvas.delete('line')
        canvas.create_line(to_canva(points_check[0]), to_canva(points_check[-1]), fill = 'black', tag = 'line')
        draw(points_check)
        
def clear():
    global points, points_spectra, points_check
    points.clear()
    points_check.clear()
    points_spectra.clear()
    canvas.delete('line')

def check():
    global points_check, points, points_spectra
    points = []
    points_spectra = []
    canvas.delete('line')
    x = draw_line()
    if x == -1:
        return
    points_check.clear()
    points_check = [x for x in points]
    points.clear()
    canvas.create_line(to_canva(points_check[0]), to_canva(points_check[-1]), fill = 'black', tag = 'line')

window = Tk()
window.title('Lab_03')
window.geometry('1200x850')
window.minsize(1200, 830)
window['bg'] = 'lavender'
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

canvas = Canvas(window, bg = 'white', width = 800, height = 800)
canvas.grid(row = 0, column = 1)
canvas.create_line(0, 400, 800, 400, tag = 'ox', arrow = 'last')
canvas.create_line(400, 0, 400, 800, tag = 'oy', arrow = 'first')

frame = Frame(window, bg = 'lavender', width = 450, height = 800)
frame.grid(row = 0, column = 0, sticky="nsew")
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
frame.rowconfigure(9, weight = 1)
frame.rowconfigure(10, weight = 1)
frame.rowconfigure(11, weight = 1)

center_lbl = Label(frame, text="Координаты отрезков", bg='lavender')
center_lbl.grid(row = 0, column = 0, columnspan = 4)
x1_lbl = Label(frame, text="X1", bg='lavender')
x1_lbl.grid(row = 1, column = 0, padx = 10, pady = 10)
y1_lbl = Label(frame, text="Y1", bg='lavender')
y1_lbl.grid(row = 1, column = 2, padx = 10, pady = 10)
x1_entry = Entry(frame, bg='white', borderwidth=0, width = 10)
x1_entry.grid(row = 1, column = 1, padx = 10)
y1_entry = Entry(frame, bg='white',borderwidth=0, width = 10)
y1_entry.grid(row = 1, column=3, padx = 10)
x1_entry.insert(END, 0)
y1_entry.insert(END, 0)
x2_lbl = Label(frame, text="X2", bg='lavender')
x2_lbl.grid(row = 2, column = 0, padx = 10, pady = 10)
y2_lbl = Label(frame, text="Y2", bg='lavender')
y2_lbl.grid(row = 2, column = 2, padx = 10, pady = 10)
x2_entry = Entry(frame,bg='white',borderwidth=0, width = 10)
x2_entry.grid(row = 2, column = 1, padx = 10, pady = 10)
y2_entry = Entry(frame,bg='white',borderwidth=0, width = 10)
y2_entry.grid(row = 2, column = 3, padx = 10, pady = 10)
x2_entry.insert(END, 250)
y2_entry.insert(END, 250)

method_lbl = Label(frame, text="Алгоритм", bg='lavender')
method_lbl.grid(row = 3, columnspan = 2, padx = 10, pady = 10)
method_combo = ttk.Combobox(frame, values=["Брезенхем (целые)", "Брезенхем (вещ)", "Брезенхем (устран. ступ.)",
                            "ЦДА", "Ву"], state = 'readonly')
method_combo.grid(row = 3, column = 2, columnspan = 2, padx = 10, pady = 10)
method_combo.current(0)

clr_button = Button(frame, text="Цвет отрезка", borderwidth=0, command=lambda: choose_line_color())
clr_button.grid(row = 4, column= 0, columnspan=2, padx = 10, pady = 10)
bgc_button = Button(frame, text="Цвет фона", borderwidth=0, command=lambda: change_bg_color())
bgc_button.grid(row = 4, column= 2, columnspan=2, padx = 10, pady = 10)

line_button = Button(frame, text="Построить отрезок", borderwidth = 0, command = draw_line)
line_button.grid(row = 5, columnspan = 4, padx = 10, pady = 10)

spectra_lable = Label(frame, text = "Пучок", bg = 'lavender')
spectra_lable.grid(row = 6, columnspan = 4, padx = 10, pady = 10)
length_label = Label(frame, text = 'Длина', bg = 'lavender')
length_label.grid(row = 7, column = 0, padx = 10, pady = 10)
length_entry = Entry(frame, width = 10)
length_entry.grid(row = 7, column = 1, padx = 10, pady = 10)
length_entry.insert(END, 100)
angle_label = Label(frame, text = 'Угол', bg = 'lavender')
angle_label.grid(row = 7, column = 2    , padx = 10, pady = 10)
angle_entry = Entry(frame, width = 10)
angle_entry.grid(row = 7, column = 3, padx = 10, pady = 10)
angle_entry.insert(END, 10)

spectra_button = Button(frame, text = 'Построить пучок', command = spectra)
spectra_button.grid(row = 8, columnspan=4)

pls_button = Button(frame, text="+", borderwidth=0, command=lambda: change_size('+'))
pls_button.grid(row = 9, columnspan = 2, padx = 10, pady = 10)
mns_button = Button(frame, text="-", borderwidth=0, command=lambda: change_size('-'))
mns_button.grid(row = 9, column = 2, columnspan = 2, padx = 10, pady = 10)

check_button = Button(frame, text = 'Сравнить с сандартным методом', command=check)
check_button.grid(row = 10, columnspan=4, padx = 10, pady = 10)

delete_button = Button(frame, text = 'Очистить', borderwidth = 0, command = clear)
delete_button.grid(row = 11, columnspan = 4)

menubar = Menu(window)  
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()