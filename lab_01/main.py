from tkinter import *
import tkinter.ttk as ttk
import tkinter.messagebox as box

def show_info():
    box.showinfo("Информация", "Сделал Динь Вьет Ань, ИУ7И-44Б")
    return

def show_error(str):
    box.showerror("Error", str)
    return

def add_point():
    try:
        x = float(entry_x.get())
        y = float(entry_y.get())
        type = int(type_combobox.get())
    except:
        show_error("Проверьте координаты точки и множество")
        return
    if type == 1:
        listbox_1.insert(END, "{};{}".format(x, y))
    else:
        listbox_2.insert(END, "{};{}".format(x, y))
    listbox_1.config(yscrollcommand = scrollbar_listbox_1.set)
    scrollbar_listbox_1.config(command = listbox_1.yview)
    listbox_2.config(yscrollcommand = scrollbar_listbox_2.set)
    scrollbar_listbox_2.config(command = listbox_2.yview)
    entry_x.delete(0, END)
    entry_y.delete(0, END)
    type_combobox.set(value = '')

def delete_point():
    point_1 = listbox_1.curselection()
    point_2 = listbox_2.curselection()
    if point_1 == () and point_2 == ():
        show_error("Выберите точку")
        return
    if point_1 != ():
        listbox_1.delete(point_1[0])
    if point_2 != ():
        listbox_2.delete(point_2[0])

def change_point():
    try:
        x_new = float(entry_x_change.get())
        y_new = float(entry_y_change.get())
    except:
        show_error("Проверьте координаты новой точки")
        return
    point_1 = listbox_1.curselection()
    point_2 = listbox_2.curselection()
    if point_1 == () and point_2 == ():
        show_error("Выберите точку для изменение")
        return
    if point_1 != ():
        listbox_1.delete(point_1[0])
        listbox_1.insert(point_1[0], "{};{}".format(x_new, y_new))
    if point_2 != ():
        listbox_2.delete(point_2[0])
        listbox_2.insert(point_2[0], "{};{}".format(x_new, y_new))
    

def solve():
    pass

window = Tk()
window.geometry("1500x900")
window['background'] = 'tomato'
window.title("Lab_01")

task_label = Label(window, text = '''Заданы два множества точек на плоскости.
В каждом множестве найти три равноудалённые друг от друга точки.
Через эти точки провести окружности. В каждую окружность вписать шестиугольник.
Найти площадь пересечения двух получивших шестиугольников.''', background="yellow")
task_label.place(x = 200, y = 10)
listbox_label_1 = Label(window, text = "Множество точек 1", width = 20)
listbox_label_1.place(x = 1200, y = 10)
listbox_label_2 = Label(window, text = "Множество точек 2", width = 20)
listbox_label_2.place(x = 1200, y = 350)
x_label = Label(window, text = "X: ", bg = "tomato", font = "Arial 14")
x_label.place(x = 1050, y = 680)
y_label = Label(window, text = "Y: ", bg = "tomato", font = "Arial 14")
y_label.place(x = 1050, y = 730)
type_label = Label(window, text = "Множество: ", bg = "tomato", font = "Arial 14")
type_label.place(x = 1050, y = 780)
x_change_label = Label(window, text = "X: ", bg = "tomato", font = "Arial 14")
x_change_label.place(x = 380, y = 830)
y_change_label = Label(window, text = "Y: ", bg = "tomato", font = "Arial 14")
y_change_label.place(x = 580, y = 830)

canvas = Canvas(window, width=1000, height=700, bg = "white")
canvas.place(x = 10, y = 100)

canvas_listbox_1 = Canvas(window, bg = "tomato")
canvas_listbox_1.place(x = 1100, y = 50)
canvas_listbox_2 = Canvas(window, bg = "tomato")
canvas_listbox_2.place(x = 1100, y = 380)

listbox_1 = Listbox(canvas_listbox_1, selectmode = SINGLE, height = 15, width = 40)
listbox_1.pack(side = LEFT, fill = BOTH)
listbox_2 = Listbox(canvas_listbox_2, selectmode = SINGLE, height = 15, width = 40)
listbox_2.pack(side = LEFT, fill = BOTH)

scrollbar_listbox_1 = Scrollbar(canvas_listbox_1)
scrollbar_listbox_1.pack(side = RIGHT, fill = BOTH)
scrollbar_listbox_2 = Scrollbar(canvas_listbox_2)
scrollbar_listbox_2.pack(side = RIGHT, fill = BOTH)

entry_x = Entry(window)
entry_x.place(x = 1100, y = 680)
entry_y = Entry(window)
entry_y.place(x = 1100, y = 730)
entry_x_change = Entry(window, width = 15)
entry_x_change.place(x = 400, y = 830)
entry_y_change = Entry(window, width = 15)
entry_y_change.place(x = 600, y = 830)

type_combobox = ttk.Combobox(window, value = ['1', '2'], state = "readonly")
type_combobox.place(x = 1200, y = 780)

add_button = Button(window, text = "Добаваить точку", command = add_point)
add_button.place(x = 1300, y = 730)
solve_button = Button(window, text = "Решить", command = solve)
solve_button.place(x = 50, y = 830)
change_button = Button(window, text = "Изменить точку", command = change_point)
change_button.place(x = 200, y = 830)
delete_button = Button(window, text = "Удалить точку", command = delete_point)
delete_button.place(x = 850, y = 830)
info_button = Button(window, text = "?", command = show_info)
info_button.place(x = 1350, y = 850)
exit_button = Button(window, text = "Выход", command = window.destroy)
exit_button.place(x = 1400, y = 850)

window.mainloop()