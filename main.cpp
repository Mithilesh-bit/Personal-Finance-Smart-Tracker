#include "expense_manager.h"
#include <iostream>
using namespace std;

const string DATA_FILE = "data.txt";

int main(){
    vector<Transaction> transactions;
    loadTransactions(DATA_FILE, transactions);

    int choice;
    do{
        cout << "\n--- Personal Finance Tracker ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. View All Transactions\n";
        cout << "3. Monthly Summary\n";
        cout << "4. Weekly Summary\n";
        cout << "5. Savings Recommendation\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice; cin.ignore();

        if(choice==1) addTransactionInteractive(transactions, DATA_FILE);
        else if(choice==2) viewAllTransactions(transactions);
        else if(choice==3) showMonthlySummary(transactions);
        else if(choice==4) showWeeklySummary(transactions);
        else if(choice==5) showSavingsRecommendation(transactions);

    } while(choice!=0);

    return 0;
}


// g++ main.cpp expense_manager.cpp analytics.cpp recommendation.cpp -o tracker
//./tracker

