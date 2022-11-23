import ctypes
import tkinter as tk
from PIL import Image, ImageTk
ctypes.windll.shcore.SetProcessDpiAwareness(True)
window = tk.Tk()
window.resizable(False, False)
img_bg = Image.open('window_bg.png')
img_bg = img_bg.resize((img_bg.width // 1, img_bg.height // 1))
img = ImageTk.PhotoImage(img_bg)
tk.Label(image = img, bg = 'white').place(x = 0, y = 0)
window.iconbitmap('ico/window.ico')
window.title('RC Car Interface')
with open('rc_car_interface_instructions.txt') as file:
    instructions = ''.join(file.readlines())
label = tk.Label(text = instructions, justify = tk.LEFT, font = ('Segoe UI Semilight', 12))
label.config(bg = 'white')
label.pack(padx = 100, pady = 100)
