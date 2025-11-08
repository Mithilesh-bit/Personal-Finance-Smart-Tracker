#include "expense_manager.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

// Add Transaction
void addTransactionInteractive(vector<Transaction>& transactions, const string& filename) {
    Transaction t;
    cout << "Enter Description: ";
    getline(cin, t.description);
    cout << "Enter Amount: ";
    cin >> t.amount; cin.ignore();
    t.category = autoCategorize(t.description);
    cout << "Enter Date (YYYY-MM-DD): ";
    getline(cin, t.date);
    cout << "Enter Payment Method(CASH,UPI,CARD): ";
    getline(cin, t.payment);

    transactions.push_back(t);
    saveTransactionToFile(t, filename);
    cout << "Transaction added successfully.\n";
}

// Save Transaction
void saveTransactionToFile(const Transaction& t, const string& filename) {
    ofstream fout(filename, ios::app);
    fout << t.description << "," << t.amount << "," << t.category << "," << t.date << "," << t.payment << "\n";
    fout.close();
}

// Load Transactions
void loadTransactions(const string& filename, vector<Transaction>& transactions) {
    ifstream fin(filename);
    if(!fin) return;
    string line;
    while(getline(fin, line)) {
        Transaction t;
        size_t start=0,pos; int field=0;
        while((pos=line.find(',',start))!=string::npos){
            string token = line.substr(start,pos-start);
            if(field==0) t.description=token;
            else if(field==1) t.amount=stod(token);
            else if(field==2) t.category=token;
            else if(field==3) t.date=token;
            start=pos+1; field++;
        }
        t.payment=line.substr(start);
        transactions.push_back(t);
    }
    fin.close();
}

// View Transactions
void viewAllTransactions(const vector<Transaction>& transactions){
    cout << left << setw(25) << "Description"
         << setw(10) << "Amount"
         << setw(20) << "Category"
         << setw(12) << "Date"
         << setw(12) << "Payment" << "\n";
    cout << string(79,'-') << "\n";
    for(auto &t: transactions){
        cout << left << setw(25) << t.description
             << setw(10) << t.amount
             << setw(20) << t.category
             << setw(12) << t.date
             << setw(12) << t.payment << "\n";
    }
    cout << "\n";
}

// Auto-Categorize with arrays (extended keywords)
string autoCategorize(string description){
    for(auto &c: description) c=tolower(c);

    string foodWords[] = { "pizza","burger","biryani","roll","snack","momos","sandwich","chicken","paneer","thali",
        "dinner","lunch","breakfast","restaurant","juice","coffee","tea","drink","cake","swiggy","zomato","beverage",
        "fastfood","pasta","noodles","samosa","doughnut","icecream","fries","chips","bread","butter","cheese",
        "milkshake","chocolate","tiffin","kebab","fish" };
    for(auto &w: foodWords) if(description.find(w)!=string::npos) return "Food";

    string travelWords[] = { "travel","bus","train","flight","taxi","uber","ola","cab","car","bike","scooter","petrol","diesel",
        "fuel","ticket","metro","parking","tour","trip","journey","transport","auto","cycle","road","highway","rail","station",
        "airport","busstop","subway","voyage","ride","fare","commute","travelpass","vehicle" };
    for(auto &w: travelWords) if(description.find(w)!=string::npos) return "Travel";

    string entertainmentWords[] = { "movie","cinema","netflix","prime","spotify","hotstar","zee5","game","music","concert",
        "party","theatre","event","match","cricket","fun","play","show","drama","tv","series","youtube","gaming","pub","club",
        "karaoke","festival","performance","exhibition","ticket","arcade","amusement","park","leisure","dance" };
    for(auto &w: entertainmentWords) if(description.find(w)!=string::npos) return "Entertainment";

    string billsWords[] = { "electricity","water","internet","wifi","recharge","mobile","gas","rent","maintenance",
        "bill","subscription","phone","connection","light","utility","tax","charge","service","broadband","cable",
        "payment","meter","dues","invoice","heating","cooling","cleaning","garbage","sewage","utilities","monthly"};
    for(auto &w: billsWords) if(description.find(w)!=string::npos) return "Bills & Utilities";

    string shoppingWords[] = { "shopping","clothes","shoes","dress","bag","gift","watch","cosmetic","perfume","makeup",
        "jewellery","amazon","flipkart","myntra","store","mall","purchase","apparel","fashion","accessories","online",
        "order","package","delivery","cart","sale","discount","coupon","offer","product","item","shoppingbag",
        "shoppingcart","retail","shop","market","brand","footwear","sunglasses","wallet","cap","belt"};
    for(auto &w: shoppingWords) if(description.find(w)!=string::npos) return "Shopping";

    string healthWords[] = { "medicine","doctor","hospital","clinic","pharmacy","gym","workout","yoga","health","checkup",
        "covid","mask","vitamin","fitness","exercise","appointment","therapy","diagnosis","treatment","vaccination"};
    for(auto &w: healthWords) if(description.find(w)!=string::npos) return "Health";

    string educationWords[] = { "book","course","college","school","fees","stationery","pen","pencil","exam","coaching",
        "onlineclass","notebook","tuition","library","education","learning","study","assignment","tutorial"};
    for(auto &w: educationWords) if(description.find(w)!=string::npos) return "Education";

    string financeWords[] = { "donation","charity","temple","insurance","investment","loan","emi","saving","tax",
        "mutualfund","bank","withdraw","deposit","paytm","googlepay","upi","credit","debit","fund","account",
        "loanpayment","interest","pension","budget","savings"};
    for(auto &w: financeWords) if(description.find(w)!=string::npos) return "Personal / Financial";

    string homeWords[] = { "furniture","sofa","bed","pillow","curtain","utensil","home","decor","paint","cleaning",
        "kitchen","grocery","vegetable","fruit","house","appliance","mattress","shelf","cabinet","lamp"};
    for(auto &w: homeWords) if(description.find(w)!=string::npos) return "Home & Family";

    return "Other";
}

