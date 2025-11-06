# Personal-Finance-Smart-Tracker

#  Personal Finance Smart Tracker  
### _A Smart CLI-based Expense Management System in C++_

---

##  Overview
The **Personal Finance Smart Tracker** is a **Command-Line Interface (CLI)** based expense management system built using **C++**.  
It helps users record, categorize, and analyze their expenses using persistent data storage.  
It also provides **automatic category classification**, **monthly analytics (ASCII visualization)**, and **rule-based savings recommendations**.

---

##  Key Features
- ✅ Add & manage daily expenses  
- ✅ Automatic category classification (Food, Transport, Bills, etc.)  
- ✅ Persistent data storage (data saved even after closing program)  
- ✅ ASCII-based charts for analytics  
- ✅ Smart savings recommendations  
- ✅ Clean, easy-to-use CLI interface  

---

##  Tech Stack
- **Language:** C++  
- **Files:**
  - `main.cpp` → Menu & user interface  
  - `expense_manager.h` → Structs & declarations  
  - `expense_manager.cpp` → Expense logic (add/view/load/save)  
  - `analytics.cpp` → Monthly spending charts  
  - `recommendation.cpp` → Smart savings advice  
- **Storage:** Local text/CSV file  

---

##  How to Run
```bash
# Clone this repository
git clone https://github.com/<your-username>/personal-finance-smart-tracker.git

# Go to the project folder
cd personal-finance-smart-tracker

# Compile
g++ main.cpp expense_manager.cpp analytics.cpp recommendation.cpp -o tracker

# Run
./tracker
