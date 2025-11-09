import tkinter as tk
from tkinter import messagebox

# Function to calculate monthly payment
def calculate():
    
        # Get user input
        principal = float(entry_principal.get())   # Loan amount
        rate = float(entry_rate.get()) / 100 / 12  # Annual → Monthly interest rate
        time = int(entry_time.get())               # Total number of months

        # Formula: EMI = [P * R] / [1 - (1 + R)^(-N)]
        emi = (principal * rate) / (1 - (1 + rate) ** -time)

        # Show result
        entry_result.delete(0, tk.END)
        entry_result.insert(0, f"{emi:.2f}")

    

# Create main window
root = tk.Tk()
root.title("Loan Calculator")
root.geometry("350x250")

# --- Labels and Entry boxes ---
tk.Label(root, text="Loan Amount (₹):").grid(row=0, column=0, padx=10, pady=5, sticky="e")
entry_principal = tk.Entry(root)
entry_principal.grid(row=0, column=1, pady=5)

tk.Label(root, text="Annual Interest Rate (%):").grid(row=1, column=0, padx=10, pady=5, sticky="e")
entry_rate = tk.Entry(root)
entry_rate.grid(row=1, column=1, pady=5)

tk.Label(root, text="Time (months):").grid(row=2, column=0, padx=10, pady=5, sticky="e")
entry_time = tk.Entry(root)
entry_time.grid(row=2, column=1, pady=5)

tk.Label(root, text="Monthly EMI (₹):").grid(row=3, column=0, padx=10, pady=5, sticky="e")
entry_result = tk.Entry(root)
entry_result.grid(row=3, column=1, pady=5)

# --- Buttons ---
tk.Button(root, text="Calculate", command=calculate).grid(row=4, column=0, pady=15)
tk.Button(root, text="Quit", command=root.destroy).grid(row=4, column=1, pady=15)

# Run app
root.mainloop()
