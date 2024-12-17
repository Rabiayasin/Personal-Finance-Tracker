#include <iostream>
using namespace std;

const int ALL_EXPENSES =  100;
int expenseCount = 0;
string category[ALL_EXPENSES];
string dateAdded[ALL_EXPENSES];
float amountToAdd[ALL_EXPENSES]; 

void addExpenses() {
    if (expenseCount > ALL_EXPENSES) {
        cout << "Expense list is full" <<endl;
        return; }

    cout << "Enter the Category for the amount addition (e.g Food, Transport, Electricity, School Bills etc):" << endl;
    cin >> category[expenseCount];
    cout << "Enter the amount you want to add: " <<endl;
    cin >> amountToAdd[expenseCount];
    cout << "Enter today's date in the format - (DD/MM/YY)" << endl;
    cin >> dateAdded[expenseCount];

    expenseCount++;
}

void viewExpenses() {
    if (expenseCount<=0)
    cout << "No Data entered yet..." <<endl;
    
    for (int i=0; i<expenseCount; i++) {
        cout << i+1 << ". Cateogry: " << category[i] << endl << "Amount: " << amountToAdd[i] << endl << "Date Added: " << dateAdded[i] <<endl;
        cout <<endl;
    }

}

void displayMenu () {
    cout << endl << "-----Your Personal Finance Tracker-----" <<endl;
    cout << "1. Add Expenses" <<endl;
    cout << "2. View All Expenses" <<endl;
    cout << "3. View All Expenses Categorically" <<endl;
    cout << "4. View Remaining Budget" <<endl;
    cout << "5. Check Monthly and Total Savings" <<endl;
    cout << "6. Check Expenses by Date Modified" <<endl;
}

int main() {
    int choice;
    while (choice !=0) {
    displayMenu();
    cout << "Enter the operation you want to add: ";
    cin >> choice;
        switch (choice) {
            case 1: {
                addExpenses();
                break;
            }

            case 2: {
                viewExpenses();
                break;
            }

            case 3: {

                break;
            }

            case 4: {

                break;
            }
        }
    }

    return 0;
}