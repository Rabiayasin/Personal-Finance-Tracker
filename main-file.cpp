//main-file.cpp
// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;


// Global variables or constants
int MAX_ENTRIES = 100;

// const int ALL_EXPENSES =  100;
// int expenseCount = 0;
// string category[ALL_EXPENSES];
// string dateAdded[ALL_EXPENSES];
// float amountToAdd[ALL_EXPENSES]; 
// All the functions:

void addEntry(string type, float amount, string category, string date);
void diplayMenu();
void askUser();
void saveDataToFile(const string& filename, float amounts[][2], string categories, string dates[], int currentIndex);
void calculateBalance(float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);
void addExpenses();
void viewExpenses();
void displayMenu();
// All the functions:



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

void displayMenu () {
    cout << endl << "-----Your Personal Finance Tracker-----" <<endl;
    cout << "1. Add Expenses" <<endl;
    cout << "2. View All Expenses" <<endl;
    cout << "3. View All Expenses Categorically" <<endl;
    cout << "4. View Remaining Budget" <<endl;
    cout << "5. Check Monthly and Total Savings" <<endl;
    cout << "6. Check Expenses by Date Modified" <<endl;
}

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

void addEntry(bool type, float amount, string category, string date,
            float amounts[][2], string categories[], string dates[], int &currentIndex){
    /*This function stores the correct data: income or expense, category and date 
    2D array to store amount and its type (0 for expense and 1 for income) 
    1D array to store category and date*/

    // Check if there's space for more enteries
    if (currentIndex >= MAX_ENTRIES) {
        cout << "No more space for entries." << endl;
    }

    // store the data in the arrays
    amounts[currentIndex][0] = amount;
    amounts[currentIndex][1] = (type == true) ? 1 : 0; // converting bool to float
    categories[currentIndex] = category;
    dates[currentIndex] = date;

    currentIndex++;
    cout<<"Entry added successfully!"<<endl;
}


void saveDataToFile(const string& file, float amounts[][2], string categories, string dates[], int currentIndex){
    // open file for writing
    ofstream outFile(file);

    // check if file opened successfully 
    if (!outFile){
        cout<<"Error: COuld not open file for writing."<<endl;
        return;
    }

    // Write each entry into the file
    for (int i=0; i<currentIndex, i++){
        outFile << amounts[i][0] << ","
                << amounts[i][1] << ","
                << categories[i] << ","
                << dates[i] << endl;
    }

    // close the file
    outFile.close();
    cout << "Data saved successfully to file: " << file <<endl;
}

}

