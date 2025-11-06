#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include <string>
#include <vector>
using namespace std;

struct Transaction {
    string description;
    double amount;
    string category;
    string date; // YYYY-MM-DD
    string payment;
};

void addTransactionInteractive(vector<Transaction>& transactions, const string& filename);
void saveTransactionToFile(const Transaction& t, const string& filename);
void loadTransactions(const string& filename, vector<Transaction>& transactions);
void viewAllTransactions(const vector<Transaction>& transactions);
string autoCategorize(string description);
void showMonthlySummary(const vector<Transaction>& transactions);
void showWeeklySummary(const vector<Transaction>& transactions);
void showSavingsRecommendation(const vector<Transaction>& transactions);

#endif
