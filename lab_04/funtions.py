from math import *

coord_center = [400, 400]

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

def canon_circle(canva, center, radius, color, draw):
    edge = round(radius / sqrt(2))
    double_radius = radius * radius
    x = 0
    while x <= edge:
        y = round(sqrt(double_radius - x * x))
        if draw:
            draw_dots_circle(canva, center, [x, y], color)
        x += 1

def canon_ellipse(canva, center, radius, color, draw):
    r_a = radius[0]
    r_b = radius[1]
    double_ra = r_a * r_a
    double_rb = r_b * r_b
    edge = round(double_ra / sqrt(double_ra + double_rb))
    x = 0
    while x <= edge:
        y = round(sqrt(1 - x * x / double_ra) * r_b)
        if draw:
            draw_dots_ellipse(canva, center, [x, y], color)
        x += 1
    edge = round(double_rb / sqrt(double_ra + double_rb))
    y = 0
    while y <= edge:
        x = round(sqrt(1 - y * y / double_rb) * r_a)
        if draw:   
            draw_dots_ellipse(canva, center, [x, y], color)
        y += 1

def parametric_circle(canvas_win, dot_c, radius, color, draw):
    x_c = dot_c[0]
    y_c = dot_c[1]
    step = 1 / radius
    alpha = 0
    while alpha < pi / 4 + step:
        x = round(radius * cos(alpha))
        y = round(radius * sin(alpha))
        if draw:
            draw_dots_circle(canvas_win, [x_c, y_c], [x, y], color)
        alpha += step

def parametric_ellipse(canvas_win, dot_c, rad, color, draw):
    x_c = dot_c[0]
    y_c = dot_c[1]
    if rad[0] > rad[1]:
        step = 1 / rad[0]
    else:
        step = 1 / rad[1]
    alpha = 0
    while alpha < pi / 2 + step:
        x = round(rad[0] * cos(alpha))
        y = round(rad[1] * sin(alpha))
        if draw:
            draw_dots_ellipse(canvas_win, [x_c, y_c], [x, y], color)
        alpha += step

def bresenham_circle(canvas_win, dot_c, radius, color, draw):
    x_c = round(dot_c[0])
    y_c = round(dot_c[1])
    x = 0
    y = radius
    delta_i = 2 * (1 - radius)
    eps = 0
    param = 1
    while x <= y:
        if draw:
            draw_dots_circle(canvas_win, [x_c, y_c], [x, y], color)
        if delta_i <= 0:
            eps = 2 * delta_i + 2 * y - 1
            param = 1 if eps < 0 else 2
        elif delta_i > 0:
            eps = 2 * delta_i - 2 * x - 1
            param = 2 if eps < 0 else 3
        if param == 1:
            x += 1
            delta_i += 2 * x + 1
        elif param == 2:
            x += 1
            y -= 1
            delta_i += 2 * x - 2 * y + 2
        else:
            y -= 1
            delta_i -= 2 * y - 1

def bresenham_ellipse(canvas_win, dot_c, rad, color, draw):
    x_c = round(dot_c[0])
    y_c = round(dot_c[1])
    x = 0
    y = rad[1]
    r_a_2 = rad[0] * rad[0]
    r_b_2 = rad[1] * rad[1]
    delta_i = r_b_2 - r_a_2 * (2 * y + 1)
    eps = 0
    param = 1
    while y >= 0:
        if draw:
            draw_dots_ellipse(canvas_win, [x_c, y_c], [x, y], color)
        if delta_i <= 0:
            eps = 2 * delta_i + (2 * y + 2) * r_a_2
            param = 1 if eps < 0 else 2
        elif delta_i > 0:
            eps = 2 * delta_i + (- 2 * x + 2) * r_b_2
            param = 2 if eps < 0 else 3
        if param == 1:
            x += 1
            delta_i += (2 * x) * r_b_2 + r_b_2
        elif param == 2:
            x += 1
            y -= 1
            delta_i += (2 * x) * r_b_2 - (2 * y) * r_a_2 + (r_a_2 + r_b_2)
        else:
            y -= 1
            delta_i -=  (2 * y) * r_a_2 - r_a_2

def mid_dot_circle(canvas_win, dot_c, radius, color, draw):
    x_c = dot_c[0]
    y_c = dot_c[1]
    x = 0
    y = radius
    delta = 1 - radius
    while x <= y:
        if draw:
            draw_dots_circle(canvas_win, [x_c, y_c], [x, y], color)
        x += 1
        if delta < 0:
            delta += 2 * x + 1
        else:
            y -= 1
            delta += 2 * (x - y) + 1

def mid_dot_ellipse(canvas_win, dot_c, rad, color, draw):
    x_c = dot_c[0]
    y_c = dot_c[1]
    x = 0
    y = rad[1]
    r_a_2 = rad[0] * rad[0]
    r_b_2 = rad[1] * rad[1]
    edge = round(rad[0] / sqrt(1 + r_b_2 / r_a_2))
    delta = r_b_2 - r_a_2* rad[1] * 2 + r_a_2
    while x <= edge:
        if draw:
            draw_dots_ellipse(canvas_win, [x_c, y_c], [x, y], color)
        if delta > 0:
            y -= 1
            delta -= r_a_2 * y * 2
        x += 1
        delta += r_b_2 * (2 * x + 1)
    x = rad[0]
    y = 0
    r_a_2 = rad[0] * rad[0]
    r_b_2 = rad[1] * rad[1]
    edge = round(rad[1] / sqrt(1 + r_a_2 / r_b_2))
    delta = r_a_2 - round(r_b_2 * (x - 1 / 4))
    while y <= edge:
        if draw:
            draw_dots_ellipse(canvas_win, [x_c, y_c], [x, y], color)
        if delta > 0:
            x -= 1
            delta -= r_b_2 * x * 2
        y += 1
        delta += r_a_2 * (2 * y + 1)