from tkinter import *
from math import *
from tkinter import ttk, colorchooser
import tkinter.messagebox as box
import colorutils as cu
import matplotlib.pyplot as plt
import numpy as np
import time

from bresenham_method import bresenham_circle, bresenham_ellipse
from mid_dot_method import mid_dot_circle, mid_dot_ellipse
from canon_method import canon_circle, canon_ellipse
from parametric_method import parametric_circle, parametric_ellipse
from draw import *

WIN_WIDTH = 1200
WIN_HEIGHT = 800

NUMBER_OF_RUNS = 3
MAX_RADIUS = 5000
STEP = 500
ITERATION = 3

task = '''Алгоритмы построения окружностей.\n 
       Реализовать возможность построения окружностей методами Брезенхема, 
средней точки, канонического и параметрического уравнений и сравненить времени.'''
current_color = (0, 0, 0)
canvas_bg = ((255, 255, 255), "#ffffff")

def show_info(str):
    box.showinfo("Информация", str)
    return

def show_error(str):
    box.showerror("Error", str)
    return
# изменение цвета фона
def change_bg_color():
    global canvas_bg
    canvas_bg = colorchooser.askcolor()
    canvas.configure(bg=cu.Color(canvas_bg[1]))
# изменение цвета отрезка
def choose_line_color():
    global current_color
    current_color = colorchooser.askcolor()

def paint(center, method, radius, type_draw, draw = True):
    color = cu.Color(current_color[0])

    if method == 0:  # canon
        if type_draw == 1:
            canon_ellipse(canvas, center, radius, color, draw)
        else:
            canon_circle(canvas, center, radius[0], color, draw)

    elif method == 1:  # param
        if type_draw == 0:
            parametric_circle(canvas, center, radius[0], color, draw)
        else:
            parametric_ellipse(canvas, center, radius, color, draw)

    elif method == 2:  # bres
        if type_draw == 0:
            bresenham_circle(canvas, center, radius[0], color, draw)
        else:
            bresenham_ellipse(canvas, center, radius, color, draw)

    elif method == 3:  # mid point
        if type_draw == 0:
            mid_dot_circle(canvas, center, radius[0], color, draw)
        else:
            mid_dot_ellipse(canvas, center, radius, color, draw)
    else:
        show_error("Неизвестный алгоритм")

def draw():
    clean()
    type1 = type1_combo.current()
    method = method_combo.current()
    rad_y = 0
    try:
        xcenter = int(xcenter_entry.get())
        ycenter = int(ycenter_entry.get())
        rad_x = int(radiusx_entry.get())
        rad_y = int(radiusy_entry.get()) if type1 else rad_x
    except:
        show_error("Ввод не правило")
        return
    if rad_x < 0 or rad_y < 0:
        show_error("Радиус не отрицательный")
        return
    paint([xcenter, ycenter], method, [rad_x, rad_y], type1)

def drawspactre():
    clean()
    type2 = type2_combo.current()
    method = method_combo.current()
    starty = 0
    step = -1
    endrad = -1
    cnt = -1
    try:
        xcenter = int(xcenter_entry.get())
        ycenter = int(ycenter_entry.get())
        startx = int(startx_entry.get())
        starty = startx if not type2 else int(starty_entry.get())
        if spectra_combo.current() == 0:
            step = int(spectra_entry.get())
        else:
            endrad = int(spectra_entry.get())
        cnt = int(number_entry.get())
    except:
        show_error("Ввод не правило")
        return
    if startx < 0 or starty < 0:
        show_error("Начальный радиус не отрицательный")
        return
    if 0 < endrad < startx and spectra_combo.current() == 1:
        show_error('Начальный радиус не может быть больше конечного')
        return 
    if 0 > step and spectra_combo.current() == 0:
        show_error('Шаг радиуса должен быть выше нуля')
        return 
    if 0 >= cnt:
        show_error('Количество должно быть больше нуля')
        return 
    if step == -1:
        step = int((endrad - startx) / (cnt - 1))
    else:
        endrad = startx + step * cnt
    for i in range(cnt):
        paint([xcenter, ycenter], method, [startx + int(i * ((endrad - startx) / (cnt - 1))), starty + int(i * ((endrad - startx) / (cnt - 1)))], type2)

def compare():
    time_mes = []

    for i in range(4):
        time_start = [0] * (MAX_RADIUS // STEP)
        time_end = [0] * (MAX_RADIUS // STEP)
        for _ in range(NUMBER_OF_RUNS):
            r_a = STEP
            r_b = STEP
            for iter in range(ITERATION):
                for k in range(MAX_RADIUS // STEP):
                    time_start[k] += time.time()
                    paint([0, 0], i, [r_a, r_b], 1, False)
                    time_end[k] += time.time()
                    r_a += STEP
                    r_b += STEP

        size = len(time_start)
        res_time = list((time_end[j] / ITERATION - time_start[j] / ITERATION) / NUMBER_OF_RUNS for j in range(size))
        time_mes.append(res_time)

    rad_arr = list(i for i in range(0, MAX_RADIUS, STEP))

    plt.title('Сранение методов построения окружности')

    plt.plot(rad_arr, time_mes[0], label="Каноническое\nуравнеие")
    plt.plot(rad_arr, time_mes[1], label="Параметрическое\nуравнение")
    plt.plot(rad_arr, time_mes[2], label="Брезенхем")
    plt.plot(rad_arr, time_mes[3], label="Алгоритм\nсредней точки")

    plt.xticks(np.arange(STEP, MAX_RADIUS, STEP))
    plt.legend()

    plt.ylabel("Время")
    plt.xlabel("Радиус")

    plt.show()

def clean():
    canvas.delete('pixel')

def block_figure(event):
    radiusy_entry.configure(state = 'normal')
    if not type1_combo.current():
        radiusy_entry.configure(state = 'readonly')
    
def block_spectra(event):
    starty_entry.configure(state = 'normal')
    if not type2_combo.current():
        starty_entry.configure(state = 'readonly')

def click(event):
    if event.x < 0 or event.x > WIN_WIDTH or event.y < 0 or event.y > WIN_HEIGHT:
        return
    point = to_coords([event.x, event.y])
    x, y = event.x, event.y
    xcenter_entry.delete(0, END)
    ycenter_entry.delete(0, END)
    xcenter_entry.insert(0, str(point[0]))
    ycenter_entry.insert(0, str(point[1]))
    canvas.delete('dot1')
    canvas.create_oval(x - 2, y - 2, x + 2, y + 2,
                            outline='grey', fill='pink', activeoutline='lightgreen', width=2, tag='dot1')

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
canvas.create_line(0, 400, 800, 400, tag = 'ox', arrow = 'last')
canvas.create_line(400, 0, 400, 800, tag = 'oy', arrow = 'first')
canvas.create_text(780, 380, text='X', font="AvantGardeC 14", fill='grey')
canvas.create_text(420, 20, text='Y', font="AvantGardeC 14", fill='grey')

canvas.bind('<1>', click)

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
frame.rowconfigure(16, weight = 1)
frame.rowconfigure(17, weight = 1)

metog_label = Label(frame, text = 'Алгоритм', bg = 'lavender')
metog_label.grid(padx = 5, pady = 10, row = 0, column = 0)
all_method = ["Каноническое уравнение", "Параметрическое уравнение", "Алгоритм Брезенхема", "Алгоритм средней точки"]
method_combo = ttk.Combobox(frame, state='readonly', width = 26,  values=all_method)
method_combo.current(0)
method_combo.grid(padx = 5, pady = 10, row = 0, column = 1)

xcenter_label = Label(frame, text = 'Х центра', bg = 'lavender')
xcenter_label.grid(padx = 5, pady = 10, row = 1, column = 0)
xcenter_entry = Entry(frame, justify = 'center')
xcenter_entry.grid(padx = 5, pady = 10, row = 1, column = 1)
ycenter_label = Label(frame, text = 'Y центра', bg = 'lavender')
ycenter_label.grid(padx = 5, pady = 10, row = 2, column = 0)
ycenter_entry = Entry(frame, justify = 'center')
ycenter_entry.grid(padx = 5, pady = 10, row = 2, column = 1)
xcenter_entry.insert(END, 0)
ycenter_entry.insert(END, 0)

figure_label = Label(frame, text = 'Построить фигуру', bg = 'lightgrey')
figure_label.grid(padx = 5, pady = 10, row = 3, columnspan = 2)
type1_combo = ttk.Combobox(frame, state='readonly', width = 15, values=["Окружность", "Эллипс"], justify = 'center')
type1_combo.grid(padx = 5, pady = 10, row = 4, columnspan = 2)
type1_combo.current(1)
type1_combo.bind('<<ComboboxSelected>>', block_figure)

radiusx_label = Label(frame, text = 'Радиус Х', bg = 'lavender')
radiusx_label.grid(padx = 5, pady = 10, row = 5, column = 0)
radiusx_entry = Entry(frame, justify = 'center')
radiusx_entry.grid(padx = 5, pady = 10, row = 5, column = 1)
radiusy_label = Label(frame, text = 'Радиус Y', bg = 'lavender')
radiusy_label.grid(padx = 5, pady = 10, row = 6, column = 0)
radiusy_entry = Entry(frame, justify = 'center')
radiusy_entry.grid(padx = 5, pady = 10, row = 6, column = 1)
radiusx_entry.insert(END, 50)
radiusy_entry.insert(END, 100)

draw_button = Button(frame, text = "Построить", command = draw)
draw_button.grid(padx = 5, pady = 10, row = 7, columnspan = 2)

sprctra_label = Label(frame, text = 'Построить фигуру', bg = 'lightgrey')
sprctra_label.grid(padx = 5, pady = 10, row = 8, columnspan = 2)
type2_combo = ttk.Combobox(frame, state='readonly', width = 15, values=["Окружность", "Эллипс"], justify = 'center')
type2_combo.grid(padx = 5, pady = 10, row = 9, columnspan = 2)
type2_combo.current(1)
type2_combo.bind('<<ComboboxSelected>>', block_spectra)

number_label = Label(frame, text = "Количество", bg = 'lavender')
number_label.grid(padx = 5, pady = 10, row = 10, column = 0)
number_entry = Entry(frame, justify = 'center')
number_entry.grid(padx = 5, pady = 10, row = 10, column = 1)
number_entry.insert(END, 10)

startx_label = Label(frame, text = 'Начальный радиус Х', bg = 'lavender')
startx_label.grid(padx = 5, pady = 10, row = 11, column = 0)
startx_entry = Entry(frame, justify = 'center')
startx_entry.grid(padx = 5, pady = 10, row = 11, column = 1)
starty_label = Label(frame, text = 'Начальный радиус Y', bg = 'lavender')
starty_label.grid(padx = 5, pady = 10, row = 12, column = 0)
starty_entry = Entry(frame, justify = 'center')
starty_entry.grid(padx = 5, pady = 10, row = 12, column = 1)
startx_entry.insert(END, 50)
starty_entry.insert(END, 100)

spectra_combo = ttk.Combobox(frame, state='readonly', width = 20, values=["Шаг", "Конечный радиус Х"], justify = 'center')
spectra_combo.grid(padx = 5, pady = 10, row = 13, column = 0)
spectra_combo.current(0)
spectra_entry = Entry(frame, justify = 'center')
spectra_entry.grid(padx = 5, pady = 10, row = 13, column = 1)

drawspactre_button = Button(frame, text = 'Построить', command = drawspactre)
drawspactre_button.grid(padx = 5, pady = 10, row = 14, columnspan = 2)

clr = Button(frame, text="Цвет фигуры", command=lambda: choose_line_color())
clr.grid(padx = 5, pady = 10, row = 15, column = 0)
bgc = Button(frame, text="Цвет фона", command=lambda: change_bg_color())
bgc.grid(padx = 5, pady = 10, row = 15, column = 1)

compare_button = Button(frame, text = 'Сранение', command = compare)
compare_button.grid(padx = 5, pady = 10, row = 16, columnspan = 2)
clean_button = Button(frame, text = 'Очистить', command = clean)
clean_button.grid(padx = 5, pady = 10, row = 17, columnspan = 2)

menubar = Menu(window) 
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)
window.config(menu = menubar)

window.mainloop()