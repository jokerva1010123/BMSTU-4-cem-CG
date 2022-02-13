from http.client import CannotSendHeader
from tkinter import *
import tkinter.messagebox as box

def show_info():
    box.showinfo("Информация", "Сделал Динь Вьет Ань, ИУ7И-44Б")
    return

window = Tk()
window.geometry("1500x900")
window['background'] = 'tomato'
window.title("Lab_01")
window.resizable(0, 0)

task_label = Label(window, text = '''Заданы два множества точек на плоскости.
В каждом множестве найти три равноудалённые друг от друга точки.
Через эти точки провести окружности. В каждую окружность вписать шестиугольник.
Найти площадь пересечения двух получивших шестиугольников.''', background="yellow")
task_label.place(x = 200, y = 10)
list_box_label_1 = Label(window, text = "Множество точек 1", width = 20)
list_box_label_1.place(x = 1200, y = 60)
list_box_label_2 = Label(window, text = "Множество точек 2", width = 20)
list_box_label_2.place(x = 1200, y = 400)

canvas = Canvas(window, width=1000, height=700, bg = "white")
canvas.place(x = 10, y = 100)

list_box_1 = Listbox(window, selectmode = SINGLE, height = 15, width = 40)
list_box_1.place(x = 1100, y = 100)
list_box_2 = Listbox(window, selectmode = SINGLE, height = 15, width = 40)
list_box_2.place(x = 1100, y = 430)

info_button = Button(window, text = "?", command = show_info)
info_button.place(x = 1350, y = 850)
exit_button = Button(window, text = "Выход", command = window.destroy)
exit_button.place(x = 1400, y = 850)

window.mainloop()