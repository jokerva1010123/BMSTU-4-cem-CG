MAIN_COLOUR = "#004543"
ADD_COLOUR = "#FFFFFF"
CANVAS_COLOUR = "#FFFFFF"

WINDOW_WIDTH = 1920
WINDOW_HEIGHT = 1000

# Frame sizes (relative).
BORDERS_PART = 0.03
BORDERS_WIDTH = int(WINDOW_WIDTH * BORDERS_PART)
BORDERS_HEIGHT = int(WINDOW_HEIGHT * BORDERS_PART)

DATA_PART_WIDTH = 0.28 - 2 * BORDERS_PART
DATA_PART_HEIGHT = 1 - 2 * BORDERS_PART
DATA_WIDTH = int(DATA_PART_WIDTH * WINDOW_WIDTH)
DATA_HEIGHT = int(DATA_PART_HEIGHT * WINDOW_HEIGHT)

FIELD_PART_WIDTH = (1 - DATA_PART_WIDTH) - 4 * BORDERS_PART
FIELD_PART_HEIGHT = 1 - 2 * BORDERS_PART
FIELD_WIDTH = int(FIELD_PART_WIDTH * WINDOW_WIDTH)
FIELD_HEIGHT = int(FIELD_PART_HEIGHT * WINDOW_HEIGHT)
CANVAS_CENTER = (FIELD_WIDTH // 2, FIELD_HEIGHT // 2)

FIELD_BORDER_PART = 0.03

ROWS = 27


METHODS = ["Каноническое уравнение", "Параметрическое уравнение", "Алгоритм Брезенхема",
           "Алгоритм средней точки", "Библиотечная функция"]
COLOURS = ["зеленый", "красный", "синий", "черный", "белый"]
NOM = len(METHODS)


class Point:
    def __init__(self, x=0, y=0, colour="#FFFFFF"):
        self.x = x
        self.y = y
        self.colour = colour


WHITE_COLOUR = "#FFFFFF"
BLACK_COLOUR = "#000000"
GREEN_COLOUR = "#00FF00"
RED_COLOUR = "#FF0000"
BLUE_COLOUR = "#0000FF"
COLOURS_CODES = [GREEN_COLOUR, RED_COLOUR, BLUE_COLOUR, BLACK_COLOUR, WHITE_COLOUR] 

CIRCLE = 0
OVAL = 1

COEFFS = [0.2, 0.2, 0.15, 0.15, 1]
