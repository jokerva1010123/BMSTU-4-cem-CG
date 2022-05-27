from tkinter import *
from tkinter import messagebox, colorchooser
from math import *
import colorutils as cu
from itertools import combinations

lines = [[]]
cutter = []

X_MIN = 0
X_MAX = 1
Y_MIN = 2
Y_MAX = 3

X_DOT = 0
Y_DOT = 1

task = '''Отсечение отрезка произвольным выпуклым отсекателем'''

color_rec = ((255, 0, 0), 0)
color_line = ((0, 255, 0), 0)
color_result = ((0, 0, 255), 0)

def change_color_rec():
    global color_rec
    color_rec = colorchooser.askcolor()

def change_color_line():
    global color_line
    color_line = colorchooser.askcolor()

def change_color_result():
    global color_result
    color_result = colorchooser.askcolor()

def add_line_click(event):
    x = event.x
    y = event.y

    add_line(x, y)

def add_line(x, y):
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

def read_dot():
    try:
        x = float(x_entry.get())
        y = float(y_entry.get())
    except:
        messagebox.showerror("Ошибка", "Неверно введены координаты точки")
        return
    add_dot(int(x), int(y))

def del_dot():
    if (is_maked()):
        return
    cur_dot = len(cutter) - 1
    if (len(cutter) == 0):
        return
    if (len(cutter) > 1):
        canvas.create_line(cutter[cur_dot - 1], cutter[cur_dot], fill = "white")
    index = len(cutter)
    dotslist_box.delete(index - 1, END)
    cutter.pop(len(cutter) - 1)

def add_dot_click(event):
    x = event.x
    y = event.y

    add_dot(x, y)

def add_line(x, y):
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

def read_line():
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

def is_maked():
    maked = False
    if (len(cutter) > 3):
        if ((cutter[0][0] == cutter[len(cutter) - 1][0]) and (cutter[0][1] == cutter[len(cutter) - 1][1])):
            maked = True

    return maked

def add_dot(x, y, last = True):
    if (is_maked()):
        cutter.clear()
        canvas.delete("all")
        draw_lines()
        dotslist_box.delete(0, END)

    cutter.append([x, y])
    cur_dot = len(cutter) - 1
    if (last):
        dotslist_box.insert(END, "%d. (%4d;%4d)" %(cur_dot + 1, x, y))

    if (len(cutter) > 1):
        canvas.create_line(cutter[cur_dot - 1], cutter[cur_dot], fill = cu.Color(color_rec[0]).hex)

def make_figure():
    cur_dot = len(cutter)

    if (cur_dot < 3):
        messagebox.showerror("Ошибка", "Недостаточно точек, чтобы замкнуть фигуру")

    add_dot(cutter[0][0], cutter[0][1], last = False)

def draw_lines():
    for line in lines:
        if (len(line) != 0):
            x1 = line[0][0]
            y1 = line[0][1]

            x2 = line[1][0]
            y2 = line[1][1]

            color_line = line[2]
            canvas.create_line(x1, y1, x2, y2, fill = cu.Color(color_line[0]).hex)

def clear_screen():
    global lines
    global cutter
    lines = [[]]
    cutter = []
    dotslist_box.delete(0, END)
    canvas.delete("all")

def get_vector(dot1, dot2):
    return [dot2[X_DOT] - dot1[X_DOT], dot2[Y_DOT] - dot1[Y_DOT]]

def vector_mul(vec1, vec2):
    return (vec1[0] * vec2[1] - vec1[1] * vec2[0])

def scalar_mul(vec1, vec2):
    return (vec1[0] * vec2[0] + vec1[1] * vec2[1])

def line_koefs(x1, y1, x2, y2):
    a = y1 - y2
    b = x2 - x1
    c = x1*y2 - x2*y1

    return a, b, c

def solve_lines_intersection(a1, b1, c1, a2, b2, c2):
    opr = a1*b2 - a2*b1
    opr1 = (-c1)*b2 - b1*(-c2)
    opr2 = a1*(-c2) - (-c1)*a2

    if (opr == 0):
        return -5, -5 

    x = opr1 / opr
    y = opr2 / opr

    return x, y

def is_coord_between(left_coord, right_coord, dot_coord):
    return (min(left_coord, right_coord) <= dot_coord) \
            and (max(left_coord, right_coord) >= dot_coord)

def is_dot_between(dot_left, dot_right, dot_intersec):
    return is_coord_between(dot_left[X_DOT], dot_right[X_DOT], dot_intersec[X_DOT]) \
            and is_coord_between(dot_left[Y_DOT], dot_right[Y_DOT], dot_intersec[Y_DOT])

def are_connected_sides(line1, line2):
    if ((line1[0][X_DOT] == line2[0][X_DOT]) and (line1[0][Y_DOT] == line2[0][Y_DOT])) \
            or ((line1[1][X_DOT] == line2[1][X_DOT]) and (line1[1][Y_DOT] == line2[1][Y_DOT])) \
            or ((line1[0][X_DOT] == line2[1][X_DOT]) and (line1[0][Y_DOT] == line2[1][Y_DOT])) \
            or ((line1[1][X_DOT] == line2[0][X_DOT]) and (line1[1][Y_DOT] == line2[0][Y_DOT])):
        return True
    return False

def extra_check(): 
    cutter_lines = []
    for i in range(len(cutter) - 1):
        cutter_lines.append([cutter[i], cutter[i + 1]]) 
    combs_lines = list(combinations(cutter_lines, 2)) 
    for i in range(len(combs_lines)):
        line1 = combs_lines[i][0]
        line2 = combs_lines[i][1]
        if (are_connected_sides(line1, line2)):
            continue
        a1, b1, c1 = line_koefs(line1[0][X_DOT], line1[0][Y_DOT], line1[1][X_DOT], line1[1][Y_DOT])
        a2, b2, c2 = line_koefs(line2[0][X_DOT], line2[0][Y_DOT], line2[1][X_DOT], line2[1][Y_DOT])
        dot_intersec = solve_lines_intersection(a1, b1, c1, a2, b2, c2)
        if (is_dot_between(line1[0], line1[1], dot_intersec)) \
                and (is_dot_between(line2[0], line2[1], dot_intersec)):
            return True
    return False

def check_polygon(): 
    if (len(cutter) < 3):
        return False
    sign = 1 if (vector_mul(get_vector(cutter[1], cutter[2]), get_vector(cutter[0], cutter[1])) > 0) else - 1
    for i in range(3, len(cutter)):
        if sign * vector_mul(get_vector(cutter[i - 1], cutter[i]), get_vector(cutter[i - 2], cutter[i - 1])) < 0:
            return False
    if (extra_check()):
        return False
    return True

def get_normal(dot1, dot2, pos):
    f_vect = get_vector(dot1, dot2)
    pos_vect = get_vector(dot2, pos)

    normal = [1, -f_vect[0] / f_vect[1]] if (f_vect[1]) else [0, 1]

    if (scalar_mul(pos_vect, normal) < 0):
        normal[0] = -normal[0]
        normal[1] = -normal[1]
    return normal

def cyrus_beck_algorithm(line, count):
    dot1 = line[0]
    dot2 = line[1]

    d = [dot2[X_DOT] - dot1[X_DOT], dot2[Y_DOT] - dot1[Y_DOT]]

    t_bottom = 0
    t_top = 1

    for i in range(-2, count - 2):
        normal = get_normal(cutter[i], cutter[i + 1], cutter[i + 2])
        w = [dot1[X_DOT] - cutter[i][X_DOT], dot1[Y_DOT] - cutter[i][Y_DOT]]

        d_scalar = scalar_mul(d, normal)
        w_scalar = scalar_mul(w, normal)

        if (d_scalar == 0):
            if (w_scalar < 0):
                return
            continue

        t = -w_scalar / d_scalar

        if (d_scalar > 0):
            if (t > 1):
                return
            t_bottom = max(t_bottom, t)
        elif (d_scalar < 0):
            if (t < 0):
                return
            t_top = min(t_top, t)

        if (t_bottom > t_top):
            break
    dot1_res = [round(dot1[X_DOT] + d[X_DOT] * t_bottom), round(dot1[Y_DOT] + d[Y_DOT] * t_bottom)]
    dot2_res = [round(dot1[X_DOT] + d[X_DOT] * t_top), round(dot1[Y_DOT] + d[Y_DOT] * t_top)]

    if (t_bottom <= t_top):
        canvas.create_line(dot1_res, dot2_res, fill = cu.Color(color_result[0]).hex)

def find_start_dot():
    y_max = cutter[0][Y_DOT]
    dot_index = 0

    for i in range(len(cutter)):
        if (cutter[i][Y_DOT] > y_max):
            y_max = cutter[i][Y_DOT]
            dot_index = i
    cutter.pop()
    for _ in range(dot_index):
        cutter.append(cutter.pop(0))
    cutter.append(cutter[0])
    if (cutter[-2][0] > cutter[1][0]):
        cutter.reverse()

def cut_area():
    if (not is_maked()):
        messagebox.showinfo("Ошибка", "Отсекатель не замкнут")
        return

    if (len(cutter) < 3):
        messagebox.showinfo("Ошибка", "Не задан отсекатель")
        return

    if (not check_polygon()):
        messagebox.showinfo("Ошибка", "Отсекатель должен быть выпуклым многоугольником")
        return

    canvas.create_polygon(cutter, outline = cu.Color(color_rec[0]).hex, fill = "white")
    find_start_dot()
    dot = cutter.pop()
    for line in lines:
        if (line):
            cyrus_beck_algorithm(line, len(cutter))
    cutter.append(dot)

window = Tk()
window['bg'] = 'lavender'
window.title('Lab_08')
window.geometry('1250x850')
window.minsize(1250, 850)
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

canvas = Canvas(window, bg = 'white', width = 800, height = 800)
canvas.grid(row = 0, column = 1, padx = 10, pady = 10)

canvas.bind("<3>", add_line_click)
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
frame.rowconfigure(12, weight = 1)
frame.rowconfigure(13, weight = 1)
frame.rowconfigure(14, weight = 1)
frame.rowconfigure(15, weight = 1)

add_dot_label = Label(frame, text = "Добавить точку отсекателя", bg = 'lavender')
add_dot_label.grid(row = 0, columnspan = 2, padx = 10, pady = 10)

x_text_label = Label(frame, text = "x: ", bg = 'lavender')
x_text_label.grid(row = 1, column = 0, padx = 10, pady = 10)

x_entry = Entry(frame)
x_entry.grid(row = 1, column = 1, padx = 10, pady = 10)

y_text_label = Label(frame, text = "y: ", bg = 'lavender')
y_text_label.grid(row = 2, column = 0, padx = 10, pady = 10)

y_entry = Entry(frame)
y_entry.grid(row = 2, column = 1, padx = 10, pady = 10)

dots_list_label = Label(frame, text = "Список точек")
dots_list_label.grid(row = 3, columnspan = 2, padx = 10, pady = 10)

dotslist_box = Listbox(frame, bg = "white")
dotslist_box.configure(height = 10, width = 30)
dotslist_box.grid(row = 4, columnspan = 2, padx = 10, pady = 10)

adddot_button = Button(frame, text = "Добавить точку", command = lambda: read_dot())
adddot_button.grid(row = 5, column = 0, padx = 10, pady = 10)

deldot_button = Button(frame, text = "Удалить крайнюю", command = lambda: del_dot())
deldot_button.grid(row = 5, column = 1, padx = 10, pady = 10)

make_figure_button = Button(frame, text = "Замкнуть отсекатель", command = lambda: make_figure())
make_figure_button.grid(row = 6, columnspan = 2, padx = 10, pady = 10)

cutter_text = Label(frame, text = "Добавить отрезок", bg = 'lavender')
cutter_text.grid(row = 7, columnspan = 2, padx = 10, pady = 10)

x_start_line_text = Label(frame, text = "Начало x: ", bg = 'lavender')
x_start_line_text.grid(row = 8, column = 0, padx = 10, pady = 10)

x_start_line_entry = Entry(frame)
x_start_line_entry.grid(row = 8, column = 1, padx = 10, pady = 10)

y_start_line_text = Label(frame, text = "Начало y: ", bg = 'lavender')
y_start_line_text.grid(row = 9, column = 0, padx = 10, pady = 10)

y_start_line_entry = Entry(frame)
y_start_line_entry.grid(row = 9, column = 1, padx = 10, pady = 10)


x_end_line_text = Label(frame, text = "Конец  x: ", bg = 'lavender')
x_end_line_text.grid(row = 10, column = 0, padx = 10, pady = 10)

x_end_line_entry = Entry(frame)
x_end_line_entry.grid(row = 10, column = 1, padx = 10, pady = 10)

y_end_line_text = Label(frame, text = "Конец y: ", bg = 'lavender')
y_end_line_text.grid(row = 11, column = 0, padx = 10, pady = 10)

y_end_line_entry = Entry(frame)
y_end_line_entry.grid(row = 11, column = 1, padx = 10, pady = 10)

add_line_btn = Button(frame, text = "Нарисовать отрезок", command = lambda: read_line())
add_line_btn.grid(row = 12, columnspan = 2, padx = 10, pady = 10)

changecolor_rec = Button(frame, text = 'цвет отсекателя', command = lambda: change_color_rec())
changecolor_rec.grid(row = 13, column = 0, padx = 10, pady = 10)
changecolor_line = Button(frame, text = 'цвет отрезка', command = lambda: change_color_line())
changecolor_line.grid(row = 13, column = 1, padx = 10, pady = 10)
changecolor_result = Button(frame, text = 'цвет результата', command = lambda: change_color_result())
changecolor_result.grid(row = 14, columnspan = 2, padx = 10, pady = 10)

cut_btn = Button(frame, text = "Отсечь", command = lambda: cut_area())
cut_btn.grid(row = 15, column = 0, padx = 10, pady = 10)

clear_btn = Button(frame, text = "Очистить экран", command = lambda: clear_screen())
clear_btn.grid(row = 15, column = 1, padx = 10, pady = 10)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()