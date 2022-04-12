from tkinter import *
from tkinter import messagebox

coord_center = [400, 400]
SIZE = 800
CENTER = [400, 400]

def to_coords(dot):
    x = (dot[0] - coord_center[0])
    y = (-dot[1] + coord_center[1])
    return [x, y]

def to_canva(dot):
    x = coord_center[0] + dot[0]
    y = coord_center[1] - dot[1]
    return [x, y]
        
def draw_pixel(canvas_win, dot):
    x, y = dot[0], dot[1]
    canvas_win.create_polygon([x, y], [x, y + 1],
                   [x + 1, y + 1], [x + 1, y],
                   fill=dot[2].hex, tag='pixel')

def draw_dots_circle(canvas_win, center, dot_dif, color):
    x_c, y_c = to_canva([center[0], center[1]])
    x = dot_dif[0]
    y = dot_dif[1]

    draw_pixel(canvas_win, [x_c + x, y_c + y, color])
    draw_pixel(canvas_win, [x_c - x, y_c + y, color])
    draw_pixel(canvas_win, [x_c + x, y_c - y, color])
    draw_pixel(canvas_win, [x_c - x, y_c - y, color])

    draw_pixel(canvas_win, [x_c + y, y_c + x, color])
    draw_pixel(canvas_win, [x_c - y, y_c + x, color])
    draw_pixel(canvas_win, [x_c + y, y_c - x, color])
    draw_pixel(canvas_win, [x_c - y, y_c - x, color])

def draw_dots_ellipse(canvas_win, center, dot_dif, color):
    x_c, y_c = to_canva([center[0], center[1]])

    x = dot_dif[0]
    y = dot_dif[1]

    draw_pixel(canvas_win, [x_c + x, y_c + y, color])
    draw_pixel(canvas_win, [x_c - x, y_c + y, color])
    draw_pixel(canvas_win, [x_c + x, y_c - y, color])
    draw_pixel(canvas_win, [x_c - x, y_c - y, color])