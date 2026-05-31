import tkinter as tk

print("options are 2x2,2x4")
opt = int(input("1 for 2x2,2 for 2x4: "))

if opt not in [1,2]:
    print("FUCK OF BITCHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH :~)")
    exit()

main_wd = tk.Tk()
pixel_img = tk.PhotoImage(width=1, height=1)

raw_val = {}
but_name_all = {}

macro_rows = 2
macro_cols = 2 if opt == 1 else 4

def toggle_pixel(m_row, m_col, i_row, i_col, btn):
    current_color = btn.cget("bg")
    if current_color == "gray":
        new_color = "lightgreen"
        bit_val = 1
    else:
        new_color = "gray"
        bit_val = 0
    
    btn.config(bg=new_color, activebackground=new_color)
    
    row_bits = raw_val[(m_row, m_col)][i_row]
    shift_amount = 4 - i_col
    
    if bit_val == 1:
        row_bits |= (1 << shift_amount)
    else:
        row_bits &= ~(1 << shift_amount)
        
    raw_val[(m_row, m_col)][i_row] = row_bits

def save_data():
    print("\n--- FINAL SAVED DATA ---")
    for m_row in range(macro_rows):
        for m_col in range(macro_cols):
            #hex_format = [f"0x{x:02X}" for x in raw_val[(m_row, m_col)]]
            #bin_format = [bin(x)[2:].zfill(5) for x in raw_val[(m_row, m_col)]]
            print(f"({m_row},{m_col})- {raw_val[(m_row, m_col)]}")
            #print(f"Grid ({m_row},{m_col}) Hex  : {hex_format}")
            #print(f"Grid ({m_row},{m_col}) Bits : {bin_format}\n")

def clear_grid():
    for m_row in range(macro_rows):
        for m_col in range(macro_cols):
            raw_val[(m_row, m_col)] = [0, 0, 0, 0, 0, 0, 0, 0]
            for i_row in range(8):
                for i_col in range(5):
                    btn = but_name_all[(m_row, m_col, i_row, i_col)]
                    btn.config(bg="gray", activebackground="gray")
    print("GRID CLEARED")

for m_row in range(macro_rows):
    for m_col in range(macro_cols):
        raw_val[(m_row, m_col)] = [0, 0, 0, 0, 0, 0, 0, 0]
        
        start_grid_row = m_row * 8
        start_grid_col = m_col * 5
        
        for i_row in range(8):
            for i_col in range(5):
                grid_r = start_grid_row + i_row
                grid_c = start_grid_col + i_col
                
                btn = tk.Button(
                    main_wd,
                    image=pixel_img,
                    width=20,
                    height=20,
                    bg="gray"
                )
                
                btn.config(
                    command=lambda mr=m_row, mc=m_col, ir=i_row, ic=i_col, b=btn: 
                    toggle_pixel(mr, mc, ir, ic, b)
                )
                
                p_left = 20 if (i_col == 0 and m_col > 0) else 10
                p_right = 20 if (i_col == 4 and m_col == macro_cols - 1) else 0
                p_top = 20 if (i_row == 0 and m_row > 0) else 10
                p_bottom = 20 if (i_row == 7 and m_row == macro_rows - 1) else 0
                
                btn.grid(
                    row=grid_r, 
                    column=grid_c, 
                    padx=(p_left, p_right), 
                    pady=(p_top, p_bottom)
                )
                
                but_name_all[(m_row, m_col, i_row, i_col)] = btn

save_btn = tk.Button(
    main_wd,
    text="SAVE",
    bg="blue",
    fg="white",
    font=("Arial", 10, "bold"),
    command=save_data
)
save_btn.grid(
    row=(macro_rows * 8),
    column=0,
    columnspan=(macro_cols * 5) // 2,
    pady=(10, 20),
    padx=(10, 5),
    sticky="we"
)

clear_btn = tk.Button(
    main_wd,
    text="CLEAR",
    bg="red",
    fg="white",
    font=("Arial", 10, "bold"),
    command=clear_grid
)
clear_btn.grid(
    row=(macro_rows * 8),
    column=(macro_cols * 5) // 2,
    columnspan=(macro_cols * 5) - ((macro_cols * 5) // 2),
    pady=(10, 20),
    padx=(5, 10),
    sticky="we"
)

main_wd.mainloop()
