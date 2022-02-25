from tkinter import *
from tkinter import ttk
from PIL import ImageTk, Image

class SimpleApp():
    def __init__(self, master, filename, **kwargs):
        self.master = master
        self.anpha = 0
        self.filename = filename
        self.canvas = Canvas(master, width=800, height=500, bg = "red")
        self.image = ImageTk.PhotoImage(file = self.filename)
        image_container =self.canvas.create_image(0,0, anchor="nw",image=self.image)
        
        self.canvas.bind('<ButtonPress-1>', self.__move_from)  
        self.canvas.bind('<B1-Motion>',     self.__move_to)

    def __move_from(self, event):
        self.canvas.scan_mark(event.x, event.y)

    def __move_to(self, event):
        
        pass


    def grid(self, **kw):
        """ Put CanvasImage widget on the parent widget """
        self.canvas.grid(**kw)  # place CanvasImage widget on the grid
        self.canvas.grid(sticky='nswe')  # make frame container sticky
        self.canvas.rowconfigure(0, weight=1)  # make canvas expandable
        self.canvas.columnconfigure(0, weight=1)

root = Tk()
app = SimpleApp(root, './image.png')
app.grid(row = 0, column = 0)
root.mainloop()