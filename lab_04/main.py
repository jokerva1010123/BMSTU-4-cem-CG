from tkinter import ttk, colorchooser
import tkinter.messagebox as box
from tkinter import *
from math import *
import colorutils as cu
import matplotlib.pyplot as plt
import numpy as np
import time

task = '''Алгоритмы построения окружностей.\n 
       Реализовать возможность построения окружностей методами Брезенхема, 
средней точки, канонического и параметрического уравнений и сравненить времени и ступенчатости.'''
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

def paint(center, method, radius, type):
    pass

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
        show_error("Error")
        return
    paint([xcenter, ycenter], method, [rad_x, rad_y], type1)

def drawspactre():
    clean()
    type2 = type2_combo.current()
    method = method_combo.current()
    try:
        xcenter = int(xcenter_entry.get())
        ycenter = int(ycenter_entry.get())
        startx = int(startx_entry.get())
        starty = int(starty_entry.get())
    except:
        show_error("Error")
        return

def compare():
    print(4)

def clean():
    canvas.delete('line')

def block_figure(event):
    radiusy_entry.configure(state = 'normal')
    if not type1_combo.current():
        radiusy_entry.configure(state = 'readonly')
    
def block_spectra(event):
    starty_entry.configure(state = 'normal')
    if not type2_combo.current():
        starty_entry.configure(state = 'readonly')

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
method_combo = ttk.Combobox(frame, state='readonly', width = 26, values=["Каноническое уравнение", "Параметрическое уравнение",
                                                           "Алгоритм Брезенхема", "Алгоритм средней точки"])
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
radiusy_entry.insert(END, 50)

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
starty_entry.insert(END, 50)

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