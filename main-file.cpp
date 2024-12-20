//main-file.cpp
// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

// Global variables or constants
int MAX_ENTRIES = 100;
const int MAX_MONTHS = 12;

// All the functions:

void addEntry(bool type, double amount, string category, string date, 
            double amounts[][2], string categories[], string dates[], int &currentIndex);
void askUser(bool type, double amount, string category, string date);
void saveDataToFile(const string& filename, float amounts[][2], string categories,
                     string dates[], int currentIndex);
void calculateBalance(float amounts[][2], int currentIndex, float &totalIncome,
                     float &totalExpenses, float &balance);
void addExpenses(bool type, double amount, string category, string date,
            double amounts[][2], string categories[], string dates[], int &currentIndex);
void viewExpenses(double amounts[][2], string categories[], 
                string dates[], int &currentIndex);
void viewExpensesCategorically (string categories[], int amounts[][2], int currentIndex);
void displayMenu();

double calculateMonthlySavings(const string months[], double amounts[][2], int numMonths, const string& targetMonth);
double calculateTotalSavings(double amounts[][2], int numMonths);
void checkExpensesByDate(const string dates[], double amounts[][2], int size, const string &targetDate);

// All the functions:

int main() {
    int choice;
    string categories[MAX_ENTRIES]; 
    double amounts[MAX_ENTRIES][2];
    string dates[MAX_ENTRIES];
    int currentIndex = 0;
    while (choice !=0) {
    displayMenu();
    cout << "Enter the operation you want to add: ";
    cin >> choice;
        switch (choice) {
            case 1: {
                bool type;
                double amount;
                string category;
                string date;

                askUser(type, amount, category, date);
                addEntry(type, amount, category, date, amounts[][2], categories[], dates[], &currentIndex);
                break;
            }

            case 2: {
                viewExpenses(amounts, categories, dates, &currentIndex);
                break;
            }

            case 3: {
                viewExpensesCategorically(categories[], amounts[][2], currentIndex);
                break;
            }

            case 4: {
                string targetMonth;
	            double income[];
                string months[MAX_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
          
	            cout<<"Enter the month for which you want to display the total savings: ";
                cin>>targetMonth;
                calculateMonthlySavings(months, amounts, MAX_MONTHS, targetMonth);
                //function for calculating monthly savings
                calculateTotalSavings(amounts, MAX_MONTHS );
                //function for calculating total savings
             break;
            }
            case 5: {
                string targetDate;
                cout<<"Enter the date to check expenses: ";
                getline(cin, targetDate);
                checkExpensesByDate(dates, amounts, targetDate);
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
    cout << "4. Check Monthly and Total Savings" <<endl;
    cout << "5. Check Expenses by Date Modified" <<endl;
}

void askUser (bool &type, double &amount, string &category, string &date) {
    cout << "Enter the type of entry (1 for income, 0 for expense)" <<endl;
    cin >> type;
    double amount;
    cout << "Enter the amount: " <<endl;
    cin >> amount;
    cout << "Enter the category of the amount: (Food, Electricity, School Bills etc)" <<endl;
    getline(cin, category);
    cin.ignore();
    cout << "Enter the date of the expenditure: " <<endl;
    getline (cin, date);
}

void viewExpenses(double amounts[][2], string categories[], 
                string dates[], int &currentIndex) {
    int choice;
    if (currentIndex <=0)
    cout << "No Data entered yet." <<endl;
    
    else {
        cout << "Do you wish to view income (1), expense (0), or both (2)." << endl;
        cin >> choice;

    if (choice ==0) { // for expense
            cout << "Your expense details are: " <<endl;
        for (int i=0; i<currentIndex; i++) {
            if (amounts[i][1] == 0){
                cout << "Index: " << i+1 << endl << "Category: " << categories[i] << endl; 
                cout << "Amount: " << amounts[i][0] << endl << "Date Added: " << dates[i] <<endl;
                cout <<endl;
                }
            }
        }

        else if (choice ==1) { // for income
            cout << "Your income details are: " <<endl;
        for (int i=0; i<currentIndex; i++) {
            if (amounts[i][1] == 1) {
                cout << "Index: " << i+1 << endl; 
                cout << "Amount: " << amounts[i][1] << endl << "Date Added: " << dates[i] <<endl;
                cout <<endl;
                }
            }
        }

        else if (choice == 2) { // for both
            cout << "Your expense details are: " <<endl;
        for (int i=0; i<currentIndex; i++) {
            if (amounts[i][1] == 0){
                cout << "Index: " << i+1 << endl << "Category: " << categories[i] << endl; 
                cout << "Amount: " << amounts[i][0] << endl << "Date Added: " << dates[i] <<endl;
                cout <<endl;
                }
            }

            cout << "Your income details are: " <<endl;
        for (int i=0; i<currentIndex; i++) {
            if (amounts[i][1] == 1) {
                cout << "Index: " << i+1 << endl; 
                cout << "Amount: " << amounts[i][1] << endl << "Date Added: " << dates[i] <<endl;
                cout <<endl;
                }
            }
        }
        else
        cout << "Choice entered is not valid!" <<endl;
    }
}

void addEntry(bool type, double amount, string category, string date,
            double amounts[][2], string categories[], string dates[], int &currentIndex){
    /*This function stores the correct data: income or expense, category and date 
    2D array to store amount and its type (0 for expense and 1 for income) 1D array to store category and date*/
    if (currentIndex >= MAX_ENTRIES) {
        cout << "No more space for entries." << endl;
        return;
    }
    // store the data in the arrays
    amounts[currentIndex][0] = amount;
    amounts[currentIndex][1] = (type == true) ? 1 : 0; // converting bool to float
    categories[currentIndex] = category;
    dates[currentIndex] = date;

    currentIndex++;
    cout<<"Entry added successfully!"<<endl;
}

void viewExpensesCategorically (string categories[], int amounts[][2], int currentIndex) {
    string enteredCategory;
    cout << "Enter the category you want to see the expenses of: ";
    getline(cin, enteredCategory);

    for (int i=0; i<currentIndex; i++) {
    if (enteredCategory == categories[i])
        if  (amounts[0][1] == 0)
        cout << "Category: " << categories[i] << endl << "Amount: " << amounts[i][0] <<endl;
    }
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

void calculateMonthlySavings(const string months[], double amounts[][2], int numMonths, const string &targetMonth) {
    for (int i = 0; i < numMonths; i++) {
        if (months[i] == targetMonth) {
           monthlysSavings= amounts[i][1]-amounts[i][0];
         cout << "Savings for " << targetMonth << ": " << monthlySavings << endl; 
        }
    }
     
}

void calculateTotalSavings(const double income[], const double expenses[], int numMonths) {
    double totalSavings = 0.0;
    for (int i = 0; i < numMonths; i++) {
        totalSavings += (amounts[i][1] - amounts[i][0]);
    }
    cout << "Total Savings: " << totalSavings << endl;
}

void checkExpensesByDate(const string dates[], double amounts[][2], int size, const string &targetDate){
    bool found= false;

    cout<<"Expense for date: "<<targetDate<<endl;

    for(int i=0; i<size; i++){
        if(dates[i]==targetDate){
            cout<<"Amounts: $ "<<amount[i][0]<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"No expenses for given date! "<<endl;
    }
}