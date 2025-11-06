#include "expense_manager.h"
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// ---------- Monthly Summary with ASCII Chart ----------
void showMonthlySummary(const vector<Transaction>& transactions){
    if(transactions.empty()){
        cout << "No transactions found.\n";
        return;
    }

    map<string,double> categoryTotals;
    map<string,double> monthTotals;

    cout << "\n--- Monthly Summary ---\n";
    cout << left << setw(15) << "Month" 
         << setw(20) << "Category" 
         << setw(10) << "Amount" << "\n";
    cout << string(45,'-') << "\n";

    for(auto &t : transactions){
        string month = t.date.substr(0,7); // YYYY-MM
        categoryTotals[t.category] += t.amount;
        monthTotals[month] += t.amount;
        cout << left << setw(15) << month
             << setw(20) << t.category
             << setw(10) << t.amount << "\n";
    }

    cout << "\n--- Monthly Totals ---\n";
    for(auto &m : monthTotals){
        cout << m.first << ": " << m.second << " | ";
        int bar = int(m.second/50); // scale bar
        for(int i=0;i<bar;i++) cout << "#";
        cout << "\n";
    }

    cout << "\nCategory-wise Monthly Totals:\n";
    for(auto &c: categoryTotals){
        cout << left << setw(20) << c.first << ": " << c.second << "\n";
    }
}

// ---------- Weekly Summary ----------
void showWeeklySummary(const vector<Transaction>& transactions){
    if(transactions.empty()){
        cout << "No transactions found.\n";
        return;
    }

    map<int,double> weekTotals;
    cout << "\n--- Weekly Summary ---\n";

    for(auto &t : transactions){
        int day = stoi(t.date.substr(8,2));
        int week = (day-1)/7 + 1; // week 1..5
        weekTotals[week] += t.amount;
    }

    for(auto &w: weekTotals){
        cout << "Week " << w.first << ": " << w.second << " | ";
        int bar = int(w.second/50);
        for(int i=0;i<bar;i++) cout << "#";
        cout << "\n";
    }
}
