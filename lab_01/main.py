from tkinter import *
import tkinter.ttk as ttk
import tkinter.messagebox as box
from math import *

EPS = 1e-4
task = '''Заданы два множества точек на плоскости.
В каждом множестве найти три равноудалённые друг от друга точки.
Через эти точки провести окружности. В каждую окружность вписать шестиугольник.
Найти площадь пересечения двух получивших шестиугольников.'''

def show_info(str):
    box.showinfo("Информация", str)
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
    '''entry_x.delete(0, END)
    entry_y.delete(0, END)
    type_combobox.set(value = '')'''

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
    
def find_point():
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

def draw(group_point_1, group_point_2, circle_1, circle_2, common):
    canvas.delete("all")
    points = group_point_1 + group_point_2 + common
    xmax = xmin = points[0][0]
    ymax = ymin = points[0][1]
    for i in range(len(points)):
        if points[i][0] > xmax:
            xmax = points[i][0]
        if points[i][0] < xmin:
            xmin = points[i][0]
        if points[i][1] > ymax:
            ymax = points[i][1]
        if points[i][1] < ymin:
            ymin = points[i][1]
    s_x = (800 - 50)/(xmax - xmin)
    s_y = (800 - 50)/(ymax - ymin)
    s_all = min(s_x, s_y)
    o_x = -xmin * s_all + 25
    o_y = -ymin * s_all + 25
    for i in range(len(group_point_1)):
        x = group_point_1[i][0] * s_all + o_x
        y = 800 - (group_point_1[i][1] * s_all + o_y)
        x1 = group_point_1[i-1][0] * s_all + o_x
        y1 = 800 - (group_point_1[i-1][1] * s_all + o_y)
        canvas.create_oval(x-6,y-6,x+6,y+6,fill='blue')
        canvas.create_line(x, y, x1, y1, fill = "black")
    for i in range(len(group_point_2)):
        x = group_point_2[i][0] * s_all + o_x
        y = 800 - (group_point_2[i][1] * s_all + o_y)
        x1 = group_point_2[i-1][0] * s_all + o_x
        y1 = 800 - (group_point_2[i-1][1] * s_all + o_y)
        canvas.create_line(x, y, x1, y1, fill = "black")
        canvas.create_oval(x-6,y-6,x+6,y+6,fill='green')
    if len(common) > 3:
        common_area = cal_common_square(common)
    common_point = [(point[0] * s_all + o_x, 800 - (point[1] * s_all + o_y)) for point in common]
    for i in range(len(common)):
        x = common[i][0] * s_all + o_x
        y = 800 - (common[i][1] * s_all + o_y)
        canvas.create_oval(x-6,y-6,x+6,y+6,fill='red')

    x1 = (circle_1[0] - distance(circle_1, group_point_1[0])) * s_all + o_x
    y1 = 800 - ((circle_1[1] - distance(circle_1, group_point_1[1])) * s_all + o_y)
    x2 = (circle_1[0] + distance(circle_1, group_point_1[0])) * s_all + o_x
    y2 = 800 - ((circle_1[1] + distance(circle_1, group_point_1[1])) * s_all + o_y)

    x3 = (circle_2[0] - distance(circle_2, group_point_2[0])) * s_all + o_x
    y3 = 800-((circle_2[1] - distance(circle_2, group_point_2[1])) * s_all + o_y)
    x4 = (circle_2[0] + distance(circle_2, group_point_2[0])) * s_all + o_x
    y4 = 800-((circle_2[1] + distance(circle_2, group_point_2[1])) * s_all + o_y)

    canvas.create_oval(x1, y1, x2, y2)
    canvas.create_oval(x3, y3, x4, y4)
    canvas.create_line(o_x, 0, o_x, 800)
    canvas.create_line(0, 800 - o_y, 1000, 800 - o_y)
    canvas.create_polygon(common_point, fill = 'red', outline = 'black')
    show_info("Площадь пересечения: " + str(round(common_area, 5)))

def solve():
    group_point_1, group_point_2, circle_1, circle_2, common = find_point()
    if group_point_1 == [] or group_point_2 == []:
        return
    draw(group_point_1, group_point_2, circle_1, circle_2, common)

def delete_all():
    canvas.delete('all')
    canvas.create_line(0, 400, 1000, 400)
    canvas.create_line(500, 0, 500, 800)
    entry_x.delete(0, 'end')
    entry_x_change.delete(0, 'end')
    entry_y.delete(0, 'end')
    entry_y_change.delete(0, 'end')
    listbox_1.delete(0, 'end')
    listbox_2.delete(0, 'end')
    type_combobox.set('')

window = Tk()
window.geometry("1500x900")
window['background'] = 'tomato'
window.title("Lab_01")

window.columnconfigure(0, weight = 1)
window.columnconfigure(1, weight = 1)
window.rowconfigure(0, weight = 1)

frame_left = Frame(window, width = 1000, height = 850, background= "tomato")
frame_left.grid(row = 0, column = 0, padx=10, pady = 10, sticky="nsew")
frame_left.rowconfigure(0, weight = 1)
frame_left.rowconfigure(1, weight = 1)
frame_left.columnconfigure(0, weight = 1)

canvas = Canvas(frame_left, width=1000, height=800, bg = "white")
canvas.grid(row=0, column=0)
canvas.create_line(0, 400, 1000, 400)
canvas.create_line(500, 0, 500, 800)

frame_button = Frame(frame_left, width = 1000, height= 100, bg = "tomato")
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
x_change_label = Label(frame_button, text = "X: ", bg = "tomato", font = "Arial 14")
x_change_label.grid(row =0, column= 2, padx=5)
entry_x_change = Entry(frame_button, width = 20)
entry_x_change.grid(row =0, column= 3, padx=5)
y_change_label = Label(frame_button, text = "Y: ", bg = "tomato", font = "Arial 14")
y_change_label.grid(row =0, column= 4, padx=5)
entry_y_change = Entry(frame_button, width = 20)
entry_y_change.grid(row =0, column= 5, padx=5)
delete_button = Button(frame_button, text = "Удалить точку", command = delete_point)
delete_button.grid(row =0, column= 6, padx=5)
delete_button = Button(frame_button, text = "Очистить", command = delete_all)
delete_button.grid(row =0, column= 7, padx=5)

frame_right = Frame(window, width = 450, height = 850, background= "tomato")
frame_right.grid(row = 0, column = 1, padx=10, pady = 10, sticky="nsew")
frame_right.rowconfigure(0, weight = 1)
frame_right.rowconfigure(1, weight = 1)
frame_right.columnconfigure(0, weight = 1)
frame_right.columnconfigure(1, weight = 1)

frame_listbox_1 = Frame(frame_right, background = "tomato")
frame_listbox_1.grid(row=0, columnspan=2,pady = 10)
frame_listbox_2 = Frame(frame_right, background = "tomato")
frame_listbox_2.grid(row=1, columnspan=2, pady = 10)

listbox_label_1 = Label(frame_listbox_1, text = "Множество точек 1", width = 20)
listbox_label_1.pack(side="top")
listbox_label_2 = Label(frame_listbox_2, text = "Множество точек 2", width = 20)
listbox_label_2.pack(side="top")

listbox_1 = Listbox(frame_listbox_1, selectmode = SINGLE, height = 15, width = 40)
listbox_1.pack(side = LEFT, fill = "both")
listbox_2 = Listbox(frame_listbox_2, selectmode = SINGLE, height = 15, width = 40)
listbox_2.pack(side = LEFT, fill = "both")

scrollbar_listbox_1 = Scrollbar(frame_listbox_1)
scrollbar_listbox_1.pack(side = RIGHT, fill= "both")
scrollbar_listbox_2 = Scrollbar(frame_listbox_2)
scrollbar_listbox_2.pack(side = RIGHT, fill = "both")

x_label = Label(frame_right, text = "X: ", bg = "tomato", font = "Arial 14")
x_label.grid(row = 2, column=0, pady = 10)
entry_x = Entry(frame_right)
entry_x.grid(row = 2, column=1, pady = 10)
y_label = Label(frame_right, text = "Y: ", bg = "tomato", font = "Arial 14")
y_label.grid(row = 3, column=0, pady = 10)
entry_y = Entry(frame_right)
entry_y.grid(row = 3, column=1, pady = 10)

type_label = Label(frame_right, text = "Множество: ", bg = "tomato", font = "Arial 14")
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