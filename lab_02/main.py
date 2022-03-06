import numpy as np
from copy import deepcopy
from math import *
from tkinter import *
from tkinter import ttk
from tkinter import messagebox as mb

def show_info(str):
    mb.showinfo("Информация", str)
    return

a = 40
b = 60
win_size = 800
radius_point = 3
list_point = []
list_circle = []
false = "-"
inverse_matrix = [[1, 0, 0],
                  [0, 1, 0],
                  [0, 0, 1]]


def func_x(t):
    return (a + b)*cos(t)-a*cos((a+b)*t/a)


def func_y(t):
    return (a+b)*sin(t)-a*sin((a+b)*t/a)


def multiplication_matrix(matrix_a, matrix_b):
    matrix_res = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range(3):
        for j in range(3):
            temp = 0
            for k in range(3):
                temp += matrix_a[i][k] * matrix_b[k][j]
            matrix_res[i][j] = temp
    return matrix_res


def multiplication_vector(vector, matrix):
    vector_res = [0, 0, 0]

    for i in range(3): 
        temp = 0
        for k in range(3):
            temp += vector[k] * matrix[k][i]
        vector_res[i] = temp

    return vector_res


def minor(m, i, j):
    return m[(i + 1) % 3][(j + 1) % 3] * m[(i + 2) % 3][(j + 2) % 3] - \
        m[(i + 1) % 3][(j + 2) % 3] * m[(i + 2) % 3][(j + 1) % 3]


def transpose(matrix):
    matrix_res = deepcopy(matrix)

    for i in range(3):
        for j in range(0, i):
            matrix_res[i][j], matrix_res[j][i] = matrix_res[j][i], matrix_res[i][j]

    return matrix_res


def determinant(m):
    det = 0
    for i in range(3):
        det += m[0][i] * minor(m, 0, i)

    return det


def inverse_func(matrix):
    matrix_res = transpose(matrix)
    matrix_copy = deepcopy(matrix_res)

    # Ищем определитель матрицы
    det = determinant(matrix_res)
    if det == 0:
        print("det = ", det)
        # det = 1
        return

    # Ищем алгебраич. доп.
    for i in range(3):
        for j in range(3):
            matrix_res[i][j] = minor(matrix_copy, i, j) / det

    return matrix_res
    # return np.linalg.inv(matrix)

def info_show():
    info = Toplevel(window)
    info_txt = "Условия задачи: Нарисовать рисунок.\
\n\nЗатем его переместить, промасштабировать и повернуть."
    label1 = Label(info, text=info_txt, font="Verdana 14")
    label1.pack()


def print_error(string_error):
    mb.showerror(title="Ошибка", message=string_error)


def check_answer(answer):
    correct = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", " ", ".", "-"]

    for i in answer:
        if i not in correct:
            print_error("Возможно, вы ввели некорректные символы.")
            return False
    return True


def int_answer(answer):
    try:
        a = int(answer)
    except:
        print_error("Возможно, у вас вещественное значение или пустой ввод.")
        return false

    return a


def float_answer(answer):
    try:
        a = float(answer)
    except:
        print_error("Возможно, у вас пустой ввод.")
        return false

    return a


def moving_func(dx, dy):
    matrix_mov = [[1, 0, 0],
                  [0, 1, 0],
                  [dx, -dy, 1]]

    global inverse_matrix
    inverse_matrix = inverse_func(matrix_mov)

    for i in range(len(list_point)):
        list_point[i] = multiplication_vector(list_point[i], matrix_mov)
    for i in range(len(list_circle)):
        list_circle[i] = multiplication_vector(list_circle[i], matrix_mov)
    print_scene()


def rotation():
    angle = entry_angle.get()
    if (check_answer(angle) == False):
        return
    angle = float_answer(angle)
    if (angle == false):
        return

    xm = entry_angle_xm.get()
    if (check_answer(xm) == False):
        return
    xm = float_answer(xm)
    if (xm == false):
        return

    ym = entry_angle_ym.get()
    if (check_answer(ym) == False):
        return
    ym = float_answer(ym)
    if (ym == false):
        return

    # print("angle = ", angle, "Xm = ", xm, "Ym = ", ym)
    dx = -xm-400
    dy = ym-400
    # dx = -list_point[len(list_point) - 1][0]
    # dy = -list_point[len(list_point) - 1][1]

    # Переводим в радианы.
    angle *= -pi / 180
    matrix = [[cos(angle), sin(angle), 0],
              [-sin(angle), cos(angle), 0],
              [0, 0, 1]]

    matrix_mov = [[1, 0, 0],
                  [0, 1, 0],
                  [dx, dy, 1]]
    
    matrix_res = multiplication_matrix(matrix_mov, matrix)
    matrix_mov[2][0], matrix_mov[2][1] = -dx, -dy
    matrix_res = multiplication_matrix(matrix_res, matrix_mov)

    global inverse_matrix

    for i in range(len(list_point)):
        list_point[i] = multiplication_vector(list_point[i], matrix_res)
    for i in range(len(list_circle)):
        list_circle[i] = multiplication_vector(list_circle[i], matrix_res)
    inverse_matrix = inverse_func(matrix_res)

    print_scene()


def moving():
    dx = entry_dx.get()
    dy = entry_dy.get()

    if (check_answer(dx) == False):
        return
    dx = int_answer(dx)
    if (dx == false):
        return

    if (check_answer(dy) == False):
        return
    dy = int_answer(dy)
    if (dy == false):
        return

    moving_func(dx, dy)


def scale():
    kx = entry_kx.get()
    if (check_answer(kx) == False):
        return
    kx = float_answer(kx)
    if (kx == false):
        return

    ky = entry_ky.get()
    if (check_answer(ky) == False):
        return
    ky = float_answer(ky)
    if (ky == false):
        return

    if kx == 0 or ky == 0:
        print_error("При таких значениях рисунка не будет!")
        return

    xm = entry_xm.get()
    if (check_answer(xm) == False):
        return
    xm = -float_answer(xm)
    if (xm == false):
        return

    ym = entry_ym.get()
    if (check_answer(ym) == False):
        return
    ym = -float_answer(ym)
    if (ym == false):
        return

    # print("kx = ", kx, "ky = ", ky, "xm = ", xm, "ym = ", ym)

    matrix = [[kx, 0, 0],
              [0, ky, 0],
              [0, 0, 1]]

    matrix_mov = [[1, 0, 0],
                  [0, 1, 0],
                  [-400-xm, ym-400, 1]]

    matrix_res = multiplication_matrix(matrix_mov, matrix)
    matrix_mov[2][0], matrix_mov[2][1] = xm + 400, 400-ym
    matrix_res = multiplication_matrix(matrix_res, matrix_mov)

    global inverse_matrix
    # inverse_matrix = inverse_func(matrix)
    inverse_matrix = inverse_func(matrix_res)

    for i in range(len(list_point)):
        list_point[i] = multiplication_vector(list_point[i], matrix_res)
    for i in range(len(list_circle)):
        list_circle[i] = multiplication_vector(list_circle[i], matrix_res)
    print_scene()


def cancel():
    global inverse_matrix
    for i in range(len(list_point)):
        list_point[i] = np.dot(list_point[i], inverse_matrix)
    for i in range(len(list_circle)):
        list_circle[i] = np.dot(list_circle[i], inverse_matrix)
    inverse_matrix = [[1, 0, 0],
                      [0, 1, 0],
                      [0, 0, 1]]
    print_scene()

def paint_point(cordinate):
    r = 1
    t = 0
    x = cordinate[0]
    y = cordinate[1] + t
    canv.create_oval(x - r, y - r,
                     x + r, y + r, fill='black')


def paint_line(a, b):
    canv.create_line(a[0], a[1], b[0], b[1], fill="black", width=3)

def paint_oval(circle, str):
    x = circle[0][0]
    y = circle[0][1]
    rx = circle[1]
    ry = circle[2]
    canv.create_oval(x - rx, y - ry, x + rx, y + ry, fill = str, width=3)


def print_scene():
    canv.delete(ALL)
    for i in range(25):
        paint_point(list_point[i])
        paint_line(list_point[i+1], list_point[i])
    for i in range(25, len(list_point)):
        paint_point(list_point[i])
        if i < len(list_point) - 1:
            paint_line(list_point[i+1], list_point[i])

    for i in range(len(list_circle) - 1):
        if (i + 1) % 3600 == 0:
            continue
        paint_line(list_circle[i], list_circle[i + 1])

    canv.create_line(win_size/2, win_size, win_size/2, 0, width=2, arrow=LAST)
    canv.create_line(0, win_size / 2, win_size,
                     win_size / 2, width=2, arrow=LAST)
    

def add_circle(point, radius):
    x = point[0]
    y = point[1]
    for i in range(0, 3600, 1):
        list_circle.append([x + radius*cos(radians(i/10)),y + radius*sin(radians(i/10)), 1])

def create_scene():
    list_point.append([135, 523, 1])
    list_point.append([80, 479, 1])
    list_point.append([147, 427, 1])
    list_point.append([295, 397, 1])
    list_point.append([270,375, 1])
    list_point.append([221,375, 1])
    list_point.append([221,368, 1])
    list_point.append([18,368, 1])
    list_point.append([18,360, 1])
    list_point.append([221,360, 1])
    list_point.append([221,353, 1])
    list_point.append([270,353, 1])
    list_point.append([400, 309, 1])
    list_point.append([430, 282, 1])
    list_point.append([480, 282, 1])
    list_point.append([499, 294, 1])
    list_point.append([523, 294, 1])
    list_point.append([627, 338, 1])
    list_point.append([627, 383, 1])
    list_point.append([529, 383, 1])
    list_point.append([529, 395, 1])
    list_point.append([683, 395, 1])
    list_point.append([763, 523, 1])
    list_point.append([615, 515, 1])
    list_point.append([246, 515, 1])
    list_point.append([135, 523, 1])
    list_point.append([141, 560,1])
    list_point.append([227, 627, 1])
    list_point.append([646, 627, 1])
    list_point.append([745, 550, 1])
    list_point.append([763, 523, 1])

    add_circle([240, 596], 30)
    add_circle([329, 596], 30)
    add_circle([428, 596], 30)
    add_circle([527, 596], 30)
    add_circle([635, 596], 30) 
    add_circle([165, 544], 26)
    add_circle([727, 529], 26)
    add_circle([240, 596], 10)
    add_circle([329, 596], 10)
    add_circle([428, 596], 10)
    add_circle([527, 596], 10)
    add_circle([635, 596], 10) 
    add_circle([165, 544], 8)
    add_circle([727, 529], 8)

    print_scene()


def return_all():
    global inverse_matrix
    inverse_matrix = [[1, 0, 0],
                      [0, 1, 0],
                      [0, 0, 1]]
    for i in range(len(list_point) - 1, -1, -1):
        del list_point[i]
    create_scene()

if __name__ == "__main__":
    window = Tk()
    window.title('Лабораторная работа №2')
    window.geometry("1200x850")
    window.configure(bg="lavender")
    window.columnconfigure(0, weight = 1)
    window.columnconfigure(1, weight = 1)
    window.rowconfigure(0, weight = 1)

    main_menu = Menu(window)
    window.configure(menu=main_menu)
    third_item = Menu(main_menu, tearoff=0)
    main_menu.add_cascade(label="Инфор",
                          menu=third_item, font="Verdana 10")
    third_item.add_command(label="О задаче",
                           command=info_show, font="Verdana 12")
    third_item.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
    exit_menu = Menu(main_menu, tearoff = 0)
    main_menu.add_command(label = "Выход", command = window.destroy)

    canv = Canvas(window, width=800, height=800, bg="white")
    canv.grid(column = 0, row = 0)

    create_scene()

    frame = Frame(window, bg = "lavender")
    frame.grid(column = 1, row = 0)
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
    frame.columnconfigure(0, weight = 1)
    frame.columnconfigure(1, weight = 1)

    button = Button(frame, text="Перенести", width=15, command=moving, bg="thistle3")
    button.grid(columnspan = 2, row = 0, pady = 15, sticky=NSEW)
    label = Label(frame, text="dx:", bg="lavender").grid(column= 0, row  = 1)
    entry_dx = Entry(frame, width="30")
    entry_dx.grid(column = 1, row = 1, pady = 15, sticky=NSEW)
    label = Label(frame, text="dy:", bg="lavender").grid(column= 0, row  = 2)
    entry_dy = Entry(frame, width="30")
    entry_dy.grid(column = 1, row = 2, pady = 15, sticky=NSEW)

    button = Button(frame, text="Повернуть", width=15,
                    command=rotation,  bg="thistle3")
    button.grid(columnspan = 2, row = 3, pady = 15, sticky=NSEW)
    label = Label(frame, text="Угол:", bg="lavender").grid(column = 0, row = 4, pady = 15, sticky=NSEW)
    label = Label(frame, text="Xm:", bg="lavender").grid(column= 0, row = 5, pady = 15, sticky=NSEW)
    label = Label(frame, text="Ym:", bg="lavender").grid(column=0, row = 6, pady = 15, sticky=NSEW)
    entry_angle = Entry(frame, width="30")
    entry_angle.grid(column=1, row = 4, pady = 15, sticky=NSEW)

    entry_angle_xm = Entry(frame, width="30")
    entry_angle_xm.grid(column = 1, row = 5, pady = 15, sticky=NSEW)

    entry_angle_ym = Entry(frame, width="30")
    entry_angle_ym.grid(column = 1, row = 6, pady = 15, sticky=NSEW)

    button = Button(frame, text="Масштабировать", width=15,
                    command=scale,  bg="thistle3")
    button.grid(columnspan=2, row = 7, pady = 15, sticky=NSEW)

    entry_kx = Entry(frame, width="30")
    entry_kx.grid(column= 1, row = 8, pady = 15, sticky=NSEW)

    entry_ky = Entry(frame, width="30")
    entry_ky.grid(column= 1, row = 9, pady = 15, sticky=NSEW)

    entry_xm = Entry(frame, width="30")
    entry_xm.grid(column= 1, row = 10, pady = 15, sticky=NSEW)

    entry_ym = Entry(frame, width="30")
    entry_ym.grid(column= 1, row = 11, pady = 15, sticky=NSEW)

    label = Label(frame, text="kx:", bg="lavender").grid(column= 0, row = 8, pady = 15, sticky=NSEW)
    label = Label(frame, text="ky:", bg="lavender").grid(column= 0, row = 9, pady = 15, sticky=NSEW)
    label = Label(frame, text="Xm:", bg="lavender").grid(column= 0, row = 10, pady = 15, sticky=NSEW)
    label = Label(frame, text="Ym:", bg="lavender").grid(column= 0, row = 11, pady = 15, sticky=NSEW)

    button = Button(frame, text="Вернуть \nначальный рисунок", width=15,
                    command=return_all, bg="thistle3")
    button.grid(columnspan=2, row = 12, pady = 15, sticky=NSEW)

    button_del_all = Button(frame, text="Шаг назад\n(Можно только 1 раз)", width=15,
                            command=cancel, bg="thistle3")
    button_del_all.grid(columnspan=2, row = 13, pady = 15, sticky=NSEW)

    window.mainloop()

