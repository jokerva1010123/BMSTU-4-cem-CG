from tkinter import *
import tkinter.ttk as ttk
import tkinter.messagebox as box
from math import *

EPS = 1e-4
task = '''Заданы два множества точек на плоскости(-15 <= x <= 15),
(-10 <= y <= 10).В каждом множестве найти три равноудалённые друг от друга точки.
Через эти точки провести окружности. В каждую окружность вписать шестиугольник.
Найти площадь пересечения двух получивших шестиугольников.'''
            
def show_info(str):
    box.showinfo("Информация", str)
    return

def show_error(str):
    box.showerror("Error", str)
    return

def draw_point(point, str):
    x = point[0] * 40 + 600
    y = 400 - point[1] * 40
    canvas.create_oval(x-4, y - 4, x + 4, y + 4, fill = str)

def add_point():
    try:
        x = float(entry_x.get())
        y = float(entry_y.get())
        type = int(type_combobox.get())
    except:
        show_error("Проверьте координаты точки и множество")
        return
    x = round(x, 3)
    y = round(y, 3)
    if fabs(x) > 15:
        show_error("x нужно в [-15;15]")
        return
    if fabs(y) > 10:
        show_error("y нужно в [-10;10]")
        return
    if type == 1:
        listbox_1.insert(END, "{};{}".format(x, y))
        draw_point([x, y], "blue")
    else:
        listbox_2.insert(END, "{};{}".format(x, y))
        draw_point([x, y], "green")
    listbox_1.config(yscrollcommand = scrollbar_listbox_1.set)
    scrollbar_listbox_1.config(command = listbox_1.yview)
    listbox_2.config(yscrollcommand = scrollbar_listbox_2.set)
    scrollbar_listbox_2.config(command = listbox_2.yview)

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
    if fabs(x_new) > 15:
        show_error("x нужно в интревале [-15;15]")
        return
    if fabs(y_new) > 10:
        show_error("y нужно в интревале [-10;10]")
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

def add_click_1(event):
    if str(event.widget) != '.!frame.!canvas':
        return
    canvas.create_oval(event.x - 4, event.y-4, event.x+4, event.y + 4, fill = "blue")
    x = round((event.x - 600) / 40, 3)
    y = round((400 - event.y) / 40, 3)
    listbox_1.insert(END, "{};{}".format(x, y))
    listbox_1.config(yscrollcommand = scrollbar_listbox_1.set)
    scrollbar_listbox_1.config(command = listbox_1.yview)

def add_click_2(event):
    if str(event.widget) != '.!frame.!canvas':
        return
    canvas.create_oval(event.x - 4, event.y-4, event.x+4, event.y + 4, fill = 'green')
    x = round((event.x - 600) / 40, 3)
    y = round((400 - event.y) / 40, 3)
    listbox_2.insert(END, "{};{}".format(x, y))
    listbox_2.config(yscrollcommand = scrollbar_listbox_2.set)
    scrollbar_listbox_2.config(command = listbox_2.yview)

def delete_all():
    canvas.delete('all')
    canvas.create_line(0, 400, 1200, 400, arrow = "last", width = 3)
    canvas.create_line(600, 0, 600, 800, arrow = "first", width = 3)
    for i in range(20):
        canvas.create_line(0, i * 40, 1200, i * 40)
    for i in range(30):
        canvas.create_line(i * 40, 0, i * 40, 800)
    entry_x.delete(0, 'end')
    entry_x_change.delete(0, 'end')
    entry_y.delete(0, 'end')
    entry_y_change.delete(0, 'end')
    listbox_1.delete(0, 'end')
    listbox_2.delete(0, 'end')
    type_combobox.set('')

def distance(pointA, pointB):
    return sqrt((pointA[0] - pointB[0]) * (pointA[0] - pointB[0]) + (pointA[1] - pointB[1]) * (pointA[1] - pointB[1]))

def check_distance(pointA, pointB, pointC):
    return (fabs(distance(pointA, pointB) - distance(pointA, pointC)) <= EPS and \
    fabs(distance(pointA, pointB) - distance(pointC, pointB)) <= EPS and \
    fabs(distance(pointA, pointC) - distance(pointC, pointB)) <= EPS)

def find_3_point(points):
    result = []
    for i in range(len(points) - 2):
        for j in range(i + 1, len(points) - 1):
            for k in range(j + 1, len(points)):
                if check_distance(points[i], points[j], points[k]):
                    result.append(points[i])
                    result.append(points[j])
                    result.append(points[k])
                if result != []:
                    break
            if result != []:
                    break    
        if result != []:
                    break
    return result

def find_6_point(points, circle):
    return_point = []
    for x in range(len(points)):
        return_point.append(points[x])
        new_point = [circle[0] * 2 - points[x - 1][0], circle[1] * 2 - points[x - 1][1]]
        return_point.append(new_point)
    return return_point
    
def ccw(point1, point2, point3):
    return (point2[0] - point1[0])*(point3[1] - point1[1]) - (point2[1] - point1[1])*(point3[0] - point1[0])

def cal_square(points):
    sum = 0
    for x in range(len(points)):
        sum += (points[x-1][0]* points[x][1] - points[x][0] * points[x-1][1])
    return fabs(sum) / 2

def check_in(point, group_point, square):
    sum = 0
    for x in range(len(group_point)):
        sum += cal_square([point, group_point[x-1], group_point[x]])
    return ((sum - square) < EPS)

def check_intersect(pointA, pointB, pointC, pointD):
    if (((pointB[0] - pointA[0])*(pointC[1] - pointA[1]) - (pointC[0] - pointA[0])*(pointB[1] - pointA[1])) *\
       ((pointB[0] - pointA[0])*(pointD[1] - pointA[1]) - (pointD[0] - pointA[0])*(pointB[1] - pointA[1]))) > 0:
        return False
    if (((pointD[0] - pointC[0])*(pointA[1] - pointC[1]) - (pointA[0] - pointC[0])*(pointD[1] - pointC[1])) *\
       ((pointD[0] - pointC[0])*(pointB[1] - pointC[1]) - (pointB[0] - pointC[0])*(pointD[1] - pointC[1]))) > 0:
        return False
    return True

def intersect(pointA, pointB, pointC, pointD):
    common = []
    flag = 0
    if fabs(distance(pointA, pointB) - distance(pointA, pointC) - distance(pointC, pointB)) < EPS:
        common.append(pointC)
        flag = 1
    if fabs(distance(pointA, pointB) - distance(pointA, pointD) - distance(pointD, pointB)) < EPS:
        common.append(pointD)
        flag = 1
    if fabs(distance(pointC, pointD) - distance(pointA, pointC) - distance(pointA, pointD)) < EPS:
        common.append(pointA)
        flag = 1
    if fabs(distance(pointC, pointD) - distance(pointB, pointC) - distance(pointB, pointD)) < EPS:
        common.append(pointB)
        flag = 1
    if flag:
        return common
    if fabs((pointA[0] - pointB[0])*(pointC[1] - pointD[1]) - (pointC[0] - pointD[0])*(pointA[1] - pointB[1]))< EPS:
        return common
    if not flag:
        a1 = (pointA[1] - pointB[1]) / (pointA[0] - pointB[0])
        b1 = pointA[1] - a1 * pointA[0]
        a2 = (pointC[1] - pointD[1]) / (pointC[0] - pointD[0])
        b2 = pointC[1] - a2* pointC[0]
        x = (b2 - b1) / (a1 - a2)
        y = a1 * x + b1
        common.append([x, y])
    return common

def find_common(group_point_1, group_point_2):
    common = []
    square_1 = cal_square(group_point_1)
    square_2 = cal_square(group_point_2)
    for x in group_point_1:
        if check_in(x, group_point_2, square_2):
            common.append(x)
    for x in group_point_2:
        if check_in(x, group_point_1, square_1):
            common.append(x)
    for x in range(len(group_point_1)):
        for y in range(len(group_point_2)):
            if check_intersect(group_point_1[x-1], group_point_1[x], group_point_2[y-1], group_point_2[y]):
                new_point = intersect(group_point_1[x-1], group_point_1[x], group_point_2[y-1], group_point_2[y])
                for point in new_point:
                    common.append(point)
    return common

def cal_common_square(common):
    for x in range(1, len(common)):
        if common[x][0] < common[0][0] or (common[x][0] == common[0][0] and common[x][1] < common[0][1]):
            common[0], common[x] = common[x], common[0]
    for x in range(1, len(common) - 1):
        for y in range(x + 1, len(common)):
            if ccw(common[0], common[x], common[y]) < 0:
                common[x], common[y] = common[y], common[x]
    return cal_square(common)
    
def find_point(listpoint_1, listpoint_2):
    if len(listpoint_1) < 3 or len(listpoint_2) < 3:
        show_error("Недостаточно точек")
        return [], [], [], [], []
    group_point_1 = find_3_point(listpoint_1)
    group_point_2 = find_3_point(listpoint_2)
    if group_point_1 == [] or group_point_2 == []:
        show_error("Не найдены три равноудалённые точки")
        return [], [], [], [], []
    circle_1 = [sum(x[0] for x in group_point_1) / 3, sum(x[1] for x in group_point_1) / 3]
    circle_2 = [sum(x[0] for x in group_point_2) / 3, sum(x[1] for x in group_point_2) / 3]
    group_point_1 = find_6_point(group_point_1, circle_1)
    group_point_2 = find_6_point(group_point_2, circle_2)
    common = find_common(group_point_1, group_point_2)
    return group_point_1, group_point_2, circle_1, circle_2, common

def draw_line(point1, point2):
    x1 = point1[0] * 40 + 600
    y1 = 400 - point1[1] * 40
    x2 = point2[0] * 40 + 600
    y2 = 400 - point2[1] * 40
    canvas.create_line(x1, y1, x2, y2)

def draw(group_point_1, group_point_2, circle_1, circle_2, common):
    for i in range(len(common)):
        draw_point(common[i], "red")
    for i in range(len(group_point_1)):
        draw_line(group_point_1[i-1], group_point_1[i-1])
    for i in range(len(group_point_2)):
        draw_line(group_point_2[i-1], group_point_2[i-1])
    x1 = ((circle_1[0]-distance(circle_1, group_point_1[0])) * 40) + 600
    y1 = 400 - ((circle_1[1]-distance(circle_1, group_point_1[0])) * 40)
    x2 = ((circle_1[0]+distance(circle_1, group_point_1[0])) * 40) + 600
    y2 = 400 - ((circle_1[1]+distance(circle_1, group_point_1[0])) * 40)
    canvas.create_oval(x1, y1, x2, y2)

    x1 = ((circle_2[0]-distance(circle_2, group_point_2[0])) * 40) + 600
    y1 = 400 - ((circle_2[1]-distance(circle_2, group_point_2[0])) * 40)
    x2 = ((circle_2[0]+distance(circle_2, group_point_2[0])) * 40) + 600
    y2 = 400 - ((circle_2[1]+distance(circle_2, group_point_2[0])) * 40)
    canvas.create_oval(x1, y1, x2, y2)
    common_area = cal_common_square(common) if len(common) > 2 else 0
    new_common = []
    for point in common:
        x = point[0] * 40 + 600
        y = 400 - (point[1] * 40)
        new_common.append([x, y])
    canvas.create_polygon(new_common, fill = "red")
    show_info("Площадь пересечения: " + str(round(common_area, 5)))

def solve():
    canvas.delete("all")
    canvas.create_line(0, 400, 1200, 400, arrow = "last", width = 3)
    canvas.create_line(600, 0, 600, 800, arrow = "first", width = 3)
    for i in range(20):
        canvas.create_line(0, i * 40, 1200, i * 40)
    for i in range(30):
        canvas.create_line(i * 40, 0, i * 40, 800)
    points = listbox_1.get(0, END)
    listpoint_1 = []
    for i in points:
        buf = list(map(float, i.split(";")))
        listpoint_1.append(buf)
    points = listbox_2.get(0, END)
    listpoint_2 = []
    for i in points:
        buf = list(map(float, i.split(";")))
        listpoint_2.append(buf)
    for x in listpoint_1:
        draw_point(x, "blue")
    for x in listpoint_2:
        draw_point(x, "green")
    group_point_1, group_point_2, circle_1, circle_2, common = find_point(listpoint_1, listpoint_2)
    if group_point_1 == [] or group_point_2 == []:
        return
    draw(group_point_1, group_point_2, circle_1, circle_2, common)

window = Tk()
window.geometry("1550x900")
window['background'] = 'lavender'
window.title("Lab_01")
window.minsize(1400, 600)

window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

frame_left = Frame(window, width = 1200, height = 850, background= "lavender")
frame_left.grid(row = 0, column = 0, padx=10, pady = 10, sticky="nsew")
frame_left.rowconfigure(0, weight = 1)
frame_left.rowconfigure(1, weight = 1)
frame_left.columnconfigure(0, weight = 1)

canvas = Canvas(frame_left, width=1200, height=800, bg = "white")
canvas.grid(row=0, column=0)
canvas.create_line(0, 400, 1200, 400, arrow = "last", width = 3)
canvas.create_line(600, 0, 600, 800, arrow = "first", width = 3)
for i in range(20):
    canvas.create_line(0, i * 40, 1200, i * 40)
for i in range(30):
    canvas.create_line(i * 40, 0, i * 40, 800)

window.bind("<Button-1>", add_click_1)
window.bind("<Button-3>", add_click_2)

frame_button = Frame(frame_left, width = 1000, height= 100, bg = "lavender")
frame_button.grid(row = 1, column=0)
frame_button.columnconfigure(0, weight = 1)
frame_button.columnconfigure(1, weight = 1)
frame_button.columnconfigure(2, weight = 1)
frame_button.columnconfigure(3, weight = 1)
frame_button.columnconfigure(4, weight = 1)
frame_button.columnconfigure(5, weight = 1)
frame_button.columnconfigure(6, weight = 1)
frame_button.columnconfigure(7, weight = 1)
frame_button.rowconfigure(0, weight = 1)

solve_button = Button(frame_button, text = "Решить", command = solve)
solve_button.grid(row =0, column= 0, padx=5)
change_button = Button(frame_button, text = "Изменить точку", command = change_point)
change_button.grid(row =0, column= 1, padx=5)
x_change_label = Label(frame_button, text = "X: ", bg = "lavender", font = "Arial 14")
x_change_label.grid(row =0, column= 2, padx=5)
entry_x_change = Entry(frame_button, width = 20)
entry_x_change.grid(row =0, column= 3, padx=5)
y_change_label = Label(frame_button, text = "Y: ", bg = "lavender", font = "Arial 14")
y_change_label.grid(row =0, column= 4, padx=5)
entry_y_change = Entry(frame_button, width = 20)
entry_y_change.grid(row =0, column= 5, padx=5)
delete_button = Button(frame_button, text = "Удалить точку", command = delete_point)
delete_button.grid(row =0, column= 6, padx=5)
delete_button = Button(frame_button, text = "Очистить", command = delete_all)
delete_button.grid(row =0, column= 7, padx=5)

frame_right = Frame(window, width = 450, height = 850, background= "lavender")
frame_right.grid(row = 0, column = 1, padx=10, pady = 10, sticky="nsew")
frame_right.rowconfigure(0, weight = 1)
frame_right.rowconfigure(1, weight = 1)
frame_right.columnconfigure(0, weight = 1)
frame_right.columnconfigure(1, weight = 1)

frame_listbox_1 = Frame(frame_right, background = "lavender")
frame_listbox_1.grid(row=0, columnspan=2,pady = 10)
frame_listbox_2 = Frame(frame_right, background = "lavender")
frame_listbox_2.grid(row=1, columnspan=2, pady = 10)

listbox_label_1 = Label(frame_listbox_1, text = "Множество точек 1", width = 18)
listbox_label_1.pack(side="top")
listbox_label_2 = Label(frame_listbox_2, text = "Множество точек 2", width = 18)
listbox_label_2.pack(side="top")

listbox_1 = Listbox(frame_listbox_1, selectmode = SINGLE, height = 15, width = 35)
listbox_1.pack(side = LEFT, fill = "both")
listbox_2 = Listbox(frame_listbox_2, selectmode = SINGLE, height = 15, width = 35)
listbox_2.pack(side = LEFT, fill = "both")

scrollbar_listbox_1 = Scrollbar(frame_listbox_1)
scrollbar_listbox_1.pack(side = RIGHT, fill = BOTH)
scrollbar_listbox_2 = Scrollbar(frame_listbox_2)
scrollbar_listbox_2.pack(side = RIGHT, fill = BOTH)

x_label = Label(frame_right, text = "X: ", bg = "lavender", font = "Arial 14")
x_label.grid(row = 2, column=0, pady = 10)
entry_x = Entry(frame_right)
entry_x.grid(row = 2, column=1, pady = 10)
y_label = Label(frame_right, text = "Y: ", bg = "lavender", font = "Arial 14")
y_label.grid(row = 3, column=0, pady = 10)
entry_y = Entry(frame_right)
entry_y.grid(row = 3, column=1, pady = 10)

type_label = Label(frame_right, text = "Множество: ", bg = "lavender", font = "Arial 14")
type_label.grid(row = 4, column=0, pady = 10)

type_combobox = ttk.Combobox(frame_right, value = ['1', '2'], state = "readonly")
type_combobox.grid(row = 4, column=1, pady = 10)

add_button = Button(frame_right, text = "Добаваить точку", command = add_point)
add_button.grid(row = 5, columnspan = 2, pady = 10)

menubar = Menu(window)
info_menu = Menu(menubar, tearoff = 0)
info_menu.add_command(label="О авторе", command = lambda: show_info("Динь ВЬет Ань, ИУ7И-44Б"))
info_menu.add_command(label="О программе", command = lambda: show_info(task))
menubar.add_cascade(label="Инфор", menu = info_menu)
exit_menu = Menu(menubar, tearoff = 0)
menubar.add_command(label = "Выход", command = window.destroy)

window.config(menu = menubar)
window.mainloop()