from tkinter import *
from tkinter import messagebox, colorchooser
from math import *
import colorutils as cu
from itertools import combinations
import copy

X_MIN = 0
X_MAX = 1
Y_MIN = 2
Y_MAX = 3
X_DOT = 0
Y_DOT = 1

cutter = []
figure = []

lines = []

task = '''Отсечение многоугольника произвольным выпуклым отсекателем'''

color_rec = ((255, 0, 0), 0)
color_line = ((0, 255, 0), 0)
color_result = ((0, 0, 255), 0)

def show_info(str):
    messagebox.showinfo("Info", str)
    return

def show_error(str):
    messagebox.showerror("Error", str)

def change_color_rec():
    global color_rec
    color_rec = colorchooser.askcolor()

def change_color_line():
    global color_line
    color_line = colorchooser.askcolor()

def change_color_result():
    global color_result
    color_result = colorchooser.askcolor()

def is_maked(object):
    maked = False
    if (len(object) > 3):
        if ((object[0][0] == object[len(object) - 1][0]) and (object[0][1] == object[len(object) - 1][1])):
            maked = True
    return maked

def reboot_prog():
    global figure
    global cutter
    canvas.delete("all")
    cutter = []
    figure = []
    cutter_dotslist_box.delete(0, END)
    figure_dotslist_box.delete(0, END)

def draw_cutter():
    for i in range(len(cutter)):
        canvas.create_line(cutter[i - 1], cutter[i], fill = cu.Color(color_rec[0]).hex)

def add_dot_figure(x, y, last = True):
    if (is_maked(figure)): 
        figure.clear()
        canvas.delete('all')
        draw_cutter()
        figure_dotslist_box.delete(0, END)
    figure.append([x, y])
    cur_dot = len(figure) - 1
    if (last):
        figure_dotslist_box.insert(END, "%d. (%4d;%4d)" %(cur_dot + 1, x, y))
    if (len(figure) > 1):
        canvas.create_line(figure[cur_dot - 1], figure[cur_dot], fill = cu.Color(color_line[0]).hex)

def add_dot_figure_click(event):
    x = event.x
    y = event.y
    add_dot_figure(x, y)

def draw_figure():
    for i in range(len(figure)):
        canvas.create_line(figure[i - 1], figure[i], fill = cu.Color(color_line[0]).hex)

def add_dot_cutter(x, y, last = True):
    if (is_maked(cutter)): # для задания нового отсекателя
        cutter.clear()
        canvas.delete("all")
        draw_figure()
        cutter_dotslist_box.delete(0, END)
    cutter.append([x, y])
    cur_dot = len(cutter) - 1
    if (last):
        cutter_dotslist_box.insert(END, "%d. (%4d;%4d)" %(cur_dot + 1, x, y))
    if (len(cutter) > 1):
        canvas.create_line(cutter[cur_dot - 1], cutter[cur_dot], fill = cu.Color(color_rec[0]).hex)

def add_dot_cutter_click(event):
    x = event.x
    y = event.y
    add_dot_cutter(x, y)

def read_dot_cutter():
    try:
        x = float(cutter_x_entry.get())
        y = float(cutter_y_entry.get())
    except:
        show_error("Неверно введены координаты точки")
        return
    add_dot_cutter(int(x), int(y))

def read_dot_figure():
    try:
        x = float(figure_x_entry.get())
        y = float(figure_y_entry.get())
    except:
        show_error("Неверно введены координаты точки")
        return
    add_dot_figure(int(x), int(y))

def del_dot_cutter():
    if (is_maked(cutter)):
        return
    cur_dot = len(cutter) - 1
    if (len(cutter) == 0):
        return
    if (len(cutter) > 1):
        canvas.create_line(cutter[cur_dot - 1], cutter[cur_dot], fill = "white")
    # Find index for a table
    index = len(cutter)
    cutter_dotslist_box.delete(index - 1, END)
    cutter.pop(len(cutter) - 1)

def make_cutter():
    if (is_maked(cutter)):
        show_error("Фигура уже замкнута")
        return
    cur_dot = len(cutter)
    if (cur_dot < 3):
        show_error("Недостаточно точек, чтобы замкнуть фигуру")
        return
    add_dot_cutter(cutter[0][0], cutter[0][1], last = False)

def make_figure():
    if (is_maked(figure)):
        show_error("Фигура уже замкнута")
        return
    cur_dot = len(figure)
    if (cur_dot < 3):
        show_error("Недостаточно точек, чтобы замкнуть фигуру")
        return
    add_dot_figure(figure[0][0], figure[0][1], last = False)

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
        return -5, -5 # прямые параллельны
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

def extra_check(object): # чтобы не было пересечений
    lines = []
    for i in range(len(object) - 1):
        lines.append([object[i], object[i + 1]]) # разбиваю многоугольник на линии
    combs_lines = list(combinations(lines, 2)) # все возможные комбинации сторон
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

def check_polygon(): # через проход по всем точкам, поворот которых должен быть все время в одну сторону
    if (len(cutter) < 3):
        return False
    sign = 0
    if (vector_mul(get_vector(cutter[1], cutter[2]), get_vector(cutter[0], cutter[1])) > 0):
        sign = 1
    else:
        sign = -1
    for i in range(3, len(cutter)):
        if sign * vector_mul(get_vector(cutter[i - 1], cutter[i]), get_vector(cutter[i - 2], cutter[i - 1])) < 0:
            return False
    check = extra_check(cutter)
    if (check):
        return False
    if (sign < 0):
        cutter.reverse()
    return True

def get_normal(dot1, dot2, pos):
    f_vect = get_vector(dot1, dot2)
    pos_vect = get_vector(dot2, pos)
    if (f_vect[1]):
        normal = [1, -f_vect[0] / f_vect[1]]
    else:
        normal = [0, 1]
    if (scalar_mul(pos_vect, normal) < 0):
        normal[0] = -normal[0]
        normal[1] = -normal[1]
    return normal

def is_visible(dot, f_dot, s_dot):
    vec1 = get_vector(f_dot, s_dot)
    vec2 = get_vector(f_dot, dot)

    if (vector_mul(vec1, vec2) <= 0):
        return True
    else:
        return False

def get_lines_parametric_intersec(line1, line2, normal):
    d = get_vector(line1[0], line1[1])
    w = get_vector(line2[0], line1[0])
    d_scalar = scalar_mul(d, normal)
    w_scalar = scalar_mul(w, normal)
    t = -w_scalar / d_scalar
    dot_intersec = [line1[0][X_DOT] + d[0] * t, line1[0][Y_DOT] + d[1] * t]
    return dot_intersec

def sutherland_hodgman_algorythm(cutter_line, position, prev_result):
    cur_result = []
    dot1 = cutter_line[0]
    dot2 = cutter_line[1]
    normal = get_normal(dot1, dot2, position)
    prev_vision = is_visible(prev_result[-2], dot1, dot2)
    for cur_dot_index in range(-1, len(prev_result)):
        cur_vision = is_visible(prev_result[cur_dot_index], dot1, dot2)
        if (prev_vision):
            if (cur_vision):
                cur_result.append(prev_result[cur_dot_index])
            else:
                figure_line = [prev_result[cur_dot_index - 1], prev_result[cur_dot_index]]
                cur_result.append(get_lines_parametric_intersec(figure_line, cutter_line, normal))
        else:
            if (cur_vision):
                figure_line = [prev_result[cur_dot_index - 1], prev_result[cur_dot_index]]
                cur_result.append(get_lines_parametric_intersec(figure_line, cutter_line, normal))
                cur_result.append(prev_result[cur_dot_index])
        prev_vision = cur_vision
    return cur_result

def cut_area():
    if (not is_maked(cutter)):
        show_error("Отсекатель не замкнут")
        return
    if (not is_maked(figure)):
        show_error("Отекаемый многоугольник не замкнут")
        return
    if (extra_check(figure)):
        show_error("Отекаемое должно быть многоугольником")
        return
    if (len(cutter) < 3):
        show_error("Не задан отсекатель")
        return
    if (not check_polygon()):
        show_error("Отсекатель должен быть выпуклым многоугольником")
        return
    result = copy.deepcopy(figure)
    for cur_dot_ind in range(-1, len(cutter) - 1):
        line = [cutter[cur_dot_ind], cutter[cur_dot_ind + 1]]
        position_dot = cutter[cur_dot_ind + 1]
        result = sutherland_hodgman_algorythm(line, position_dot, result)
        if (len(result) <= 2):
            return
    draw_result_figure(result)

def draw_result_figure(figure_dots):
    fixed_figure = remove_odd_sides(figure_dots)
    for line in fixed_figure:
        canvas.create_line(line[0], line[1], fill = cu.Color(color_result[0]).hex)

def make_unique(sides):
    for side in sides:
        side.sort()
    return list(filter(lambda x: (sides.count(x) % 2) == 1, sides))

def is_dot_in_side(dot, side):
    if abs(vector_mul(get_vector(dot, side[0]), get_vector(side[1], side[0]))) <= 1e-6:
        if (side[0] < dot < side[1] or side[1] < dot < side[0]):
            return True
    return False

def get_sides(side, rest_dots):
    dots_list = [side[0], side[1]]
    for dot in rest_dots:
        if is_dot_in_side(dot, side):
            dots_list.append(dot)
    dots_list.sort()
    sections_list = list()
    for i in range(len(dots_list) - 1):
        sections_list.append([dots_list[i], dots_list[i + 1]])
    return sections_list

def remove_odd_sides(figure_dots):
    all_sides = list()
    rest_dots = figure_dots[2:]
    for i in range(len(figure_dots)):
        cur_side = [figure_dots[i], figure_dots[(i + 1) % len(figure_dots)]]
        all_sides.extend(get_sides(cur_side, rest_dots))
        rest_dots.pop(0)
        rest_dots.append(figure_dots[i])
    return make_unique(all_sides)

window = Tk()
window['bg'] = 'lavender'
window.title('Lab_09')
window.geometry('1250x850')
window.minsize(1250, 850)
window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

canvas = Canvas(window, bg = 'white', width = 800, height = 800)
canvas.grid(row = 0, column = 1, padx = 10, pady = 5)

canvas.bind("<1>", add_dot_cutter_click)
canvas.bind("<3>", add_dot_figure_click)

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

add_dot_text = Label(frame, text = "Добавить точку отсекателя", bg = 'lavender')
add_dot_text.grid(padx = 10, pady = 5, row = 0, columnspan = 2)

cutter_x_text = Label(frame, text = "x: ", bg = 'lavender')
cutter_x_text.grid(padx = 10, pady = 5, row = 1, column = 0)

cutter_x_entry = Entry(frame)
cutter_x_entry.grid(padx = 10, pady = 5, row = 1, column = 1)

cutter_y_text = Label(frame, text = "y: ", bg = 'lavender')
cutter_y_text.grid(padx = 10, pady = 5, row = 2, column = 0)

cutter_y_entry = Entry(frame)
cutter_y_entry.grid(padx = 10, pady = 5, row = 2, column = 1)

cutter_dots_list_text = Label(frame, text = "Список точек", width = 20, bg = 'lavender')
cutter_dots_list_text.grid(padx = 10, pady = 5, row = 3, columnspan = 2)

cutter_dotslist_box = Listbox(frame, bg = "white", height = 10, width = 23)
cutter_dotslist_box.grid(padx = 10, pady = 5, row = 4, columnspan = 2)

cutter_add_dot_btn = Button(frame, text = "Добавить точку", command = lambda: read_dot_cutter())
cutter_add_dot_btn.grid(padx = 10, pady = 5, row = 5, column = 0)

cutter_del_dot_btn = Button(frame, text = "Удалить крайнюю", command = lambda: del_dot_cutter())
cutter_del_dot_btn.grid(padx = 10, pady = 5, row = 5, column = 1)

figure_add_dot_text = Label(frame, text = "Добавить точку многоугольника", width = 43, bg = 'lavender')
figure_add_dot_text.grid(padx = 10, pady = 5, row = 6, columnspan = 2)

figure_x_text = Label(frame, text = "x: ", bg = 'lavender')
figure_x_text.grid(padx = 10, pady = 5, row = 7, column = 0)

figure_x_entry = Entry(frame)
figure_x_entry.grid(padx = 10, pady = 5, row = 7, column = 1)

figure_y_text = Label(frame, text = "y: ", bg = 'lavender')
figure_y_text.grid(padx = 10, pady = 5, row = 8, column = 0)

figure_y_entry = Entry(frame)
figure_y_entry.grid(padx = 10, pady = 5, row = 8, column = 1)

figure_dots_list_text = Label(frame, text = "Список точек", width = 20, bg = 'lavender')
figure_dots_list_text.grid(padx = 10, pady = 5, row = 9, columnspan = 2)

figure_dotslist_box = Listbox(frame, bg = "white", height = 10, width = 23)
figure_dotslist_box.grid(padx = 10, pady = 5, row = 10, columnspan = 2)

figure_add_dot_btn = Button(frame, text = "Добавить точку", command = lambda: read_dot_figure())
figure_add_dot_btn.grid(padx = 10, pady = 5, row = 11, column = 0)

figure_del_dot_btn = Button(frame, text = "Удалить крайнюю", command = lambda: del_dot_figure())
figure_del_dot_btn.grid(padx = 10, pady = 5, row = 11, column = 1)

make_cutter_btn = Button(frame, text = "Замкнуть отсекатель", command = lambda: make_cutter())
make_cutter_btn.grid(padx = 10, pady = 5, row = 12, column = 0)

make_figure_btn = Button(frame, text = "Замкнуть многоугольник", command = lambda: make_figure())
make_figure_btn.grid(padx = 10, pady = 5, row = 12, column = 1)

changecolor_rec = Button(frame, text = 'Цвет отсекателя', command = lambda: change_color_rec())
changecolor_rec.grid(row = 13, column = 0, padx = 10, pady = 5)
changecolor_line = Button(frame, text = 'Цвет отрезка', command = lambda: change_color_line())
changecolor_line.grid(row = 13, column = 1, padx = 10, pady = 5)
changecolor_result = Button(frame, text = 'Цвет результата', command = lambda: change_color_result())
changecolor_result.grid(row = 14, columnspan = 2, padx = 10, pady = 5)

cut_btn = Button(frame, text = "Отсечь", width = 18, height = 2, command = lambda: cut_area())
cut_btn.grid(padx = 10, pady = 5, row = 15, column = 0)

clear_btn = Button(frame, text = "Очистить экран", width = 18, height = 2, command = lambda: reboot_prog())
clear_btn.grid(padx = 10, pady = 5, row = 15, column = 1)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()