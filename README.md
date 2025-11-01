---

### 🧾 Bill Management System

A simple **C++ console-based billing application** for managing customer purchases in a general store.
It demonstrates strong use of **Object-Oriented Programming (OOP)** and **Data Structures and Algorithms (DSA)** principles to create, display, and store customer bills efficiently.

---

## 📋 Features

### 🛒 Billing Operations

* Create new customer bills
* Add multiple items (ID, name, price, quantity)
* Calculate **subtotal**, **discount**, **tax**, and **final total** automatically
* Display a **formatted receipt** in the console
* Save each bill to a file (`bill.txt`)
* Reopen and view the **previous bill**

### 💾 File Handling

* Saves generated bills automatically to **`bill.txt`**
* Allows viewing the last saved bill

### 🧮 Auto Calculations

* Subtotal = price × quantity
* Discount and tax applied dynamically
* Grand total shown after calculations

---

## 🧠 DSA and OOP Concepts Used

| Concept                             | Description                                                        | Where It’s Used                                           |
| ----------------------------------- | ------------------------------------------------------------------ | --------------------------------------------------------- |
| **Class & Object (OOP)**            | Encapsulates item details like ID, name, price, and quantity       | Class `iteam`                                             |
| **Encapsulation**                   | Keeps item details protected and managed via functions             | Inside class `iteam`                                      |
| **Abstraction**                     | Simplifies complex billing operations (discounts, tax, saving)     | Functions like `bill()` and `saveFile()`                  |
| **File Handling**                   | Saves and reads billing data from files                            | `ofstream` and `ifstream` used in `saveFile()` and main() |
| **Array / Looping**                 | Stores and processes multiple items in a bill                      | Array `iteam it[]` and for-loops                          |
| **Functions / Modular Programming** | Each task (display, save, input) is handled by a separate function | `bill()`, `saveFile()`, `newBill()`                       |
| **Condition Handling**              | Validates user choices and handles incorrect input                 | `switch-case` in `main()`                                 |
| **Formatting**                      | Properly aligns bill columns using `setw()`                        | In `bill()` and `saveFile()`                              |
| **Time Handling**                   | Adds date and time to each bill                                    | `time_t`, `localtime()`, and `strftime()`                 |

---

## 🧩 Code Structure

| Function          | Description                                                             |
| ----------------- | ----------------------------------------------------------------------- |
| **`class iteam`** | Stores details of each purchased item                                   |
| **`bill()`**      | Generates and displays a formatted bill with totals, tax, and discounts |
| **`saveFile()`**  | Saves the generated bill to `bill.txt`                                  |
| **`newBill()`**   | Takes input for customer and item details, then generates the bill      |
| **`main()`**      | Provides a menu to create a new bill or view the last bill              |

---

## 🧠 How It Works

1. **Program Start**

   * The user is prompted to:

     * Press **1** to generate a new bill
     * Press **2** to view the previous bill

2. **If “Generate Bill” is chosen:**

   * User enters:

     * Customer name and address
     * Number of items to purchase
     * For each item: ID, name, price, quantity
     * Discount and tax percentage
   * System calculates:

     * Subtotals per item
     * Discount, tax, and final total

3. **Bill Display and Save**

   * The full formatted bill is shown in the console
   * A copy is saved in `bill.txt`

4. **If “View Bill” is chosen:**

   * The program reads and displays the content of `bill.txt`

---

## 💾 Example Output

### Console Bill:

```
                GLOBAL GENERAL STORE
                ---------------------------

Customer Name: John Doe                         2025-11-01 15:30:21
Customer Address: 123 Main Street
-----------------------------------------------------------
| ID | Name             | Price  | Quantity | Subtotal     |
-----------------------------------------------------------
|   1 | Rice             |   120  |       2  |          240 |
|   2 | Oil              |   150  |       1  |          150 |
-----------------------------------------------------------
Discount: 39
Tax: 35
Total: 386

     Thank you for shopping with us.
     Visit Again!!
```

### Saved File (`bill.txt`):

Same as above, stored automatically after bill generation.

---

## ⚙️ Requirements

* **C++ Compiler** (g++, MinGW, or Visual Studio C++)
* **Windows OS** (uses `<conio.h>` and `<windows.h>`)

---

## 🚀 How to Run

1. **Compile the program**

   ```bash
   g++ billManagement.cpp -o billSystem
   ```

2. **Run the program**

   ```bash
   ./billSystem
   ```

3. **Follow the menu instructions**

   * Press `1` to generate a new bill
   * Press `2` to view the last bill

---

## 🧱 Future Improvements

* Add multiple bill saving with unique file names
* Store and retrieve customer history
* Improve formatting and add colors
* Handle invalid inputs (negative price or quantity)
* Add product database for reusability

---

## 🧑‍💻 Author

* **Created by:** *Ashutosh Maurya*
* **Project:** Bill Management System
* **Language:** C++
* **Concepts Demonstrated:** *OOP, Encapsulation, Abstraction, File Handling, Loops, Time Functions*

---
