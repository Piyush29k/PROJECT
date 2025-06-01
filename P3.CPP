#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Person {
public:
    string name;
    double totalSpent;
    double balance;

    Person(string name, double spent) {
        this->name = name;
        this->totalSpent = spent;
        this->balance = 0.0;
    }
};

class ExpenseManager {
private:
    vector<Person> people;
    double totalExpense = 0;
    double equalShare = 0;

public:
    void inputData(int n) {
        for (int i = 0; i < n; ++i) {
            string name;
            double amount;

            cout << "Enter name of person " << i + 1 << ": ";
            cin >> ws; // Clean up newline
            getline(cin, name);

            cout << "Enter total amount spent by " << name << ": ";
            cin >> amount;

            people.push_back(Person(name, amount));
            totalExpense += amount;
        }
    }

    void calculateShare() {
        if (people.empty()) return;
        equalShare = totalExpense / people.size();

        for (auto &person : people) {
            person.balance = person.totalSpent - equalShare;
        }

        cout << fixed << setprecision(2);
        cout << "\nTotal Expense: ₹" << totalExpense << endl;
        cout << "Equal Share: ₹" << equalShare << endl;
    }

    void settleExpenses() {
        vector<pair<string, double>> debtors;
        vector<pair<string, double>> creditors;

        for (const auto &person : people) {
            if (person.balance < 0) {
                debtors.push_back({person.name, -person.balance});
            } else if (person.balance > 0) {
                creditors.push_back({person.name, person.balance});
            }
        }

        cout << "\n--- Settlements ---\n";
        int i = 0, j = 0;
        while (i < debtors.size() && j < creditors.size()) {
            double amount = min(debtors[i].second, creditors[j].second);
            cout << debtors[i].first << " pays ₹" << amount << " to " << creditors[j].first << endl;

            debtors[i].second -= amount;
            creditors[j].second -= amount;

            if (debtors[i].second == 0) ++i;
            if (creditors[j].second == 0) ++j;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of people: ";
    cin >> n;

    ExpenseManager manager;
    manager.inputData(n);
    manager.calculateShare();
    manager.settleExpenses();

    return 0;
}
