#include "expense_manager.h"
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

// ---------- Smart Savings Recommendation ----------
void showSavingsRecommendation(const vector<Transaction>& transactions){
    if(transactions.empty()){
        cout << "No transactions to analyze for savings.\n";
        return;
    }

    map<string,double> categoryTotals;
    double total=0;

    for(auto &t : transactions){
        categoryTotals[t.category] += t.amount;
        total += t.amount;
    }

    cout << "\n--- Smart Savings Recommendation ---\n";

    for(auto &c : categoryTotals){
        if(c.second==0) continue;
        double suggestion = c.second * 0.1; // suggest saving 10%
        cout << left << setw(20) << c.first
             << "Total: " << setw(8) << c.second
             << " | Suggested Saving: " << suggestion
             << " | Tip: ";
        if(c.first=="Food") cout << "Cook at home more often.\n";
        else if(c.first=="Travel") cout << "Use public transport.\n";
        else if(c.first=="Entertainment") cout << "Limit subscriptions.\n";
        else if(c.first=="Bills & Utilities") cout << "Check electricity usage.\n";
        else if(c.first=="Shopping") cout << "Buy only essentials.\n";
        else if(c.first=="Health") cout << "Home workout or fewer gym classes.\n";
        else if(c.first=="Education") cout << "Use free online resources.\n";
        else if(c.first=="Personal / Financial") cout << "Plan EMI and avoid impulse loan.\n";
        else if(c.first=="Home & Family") cout << "Plan grocery list and buy bulk.\n";
        else cout << "Review spending.\n";
    }

    cout << "\nOverall potential savings: " << total*0.1 << "\n";
}
