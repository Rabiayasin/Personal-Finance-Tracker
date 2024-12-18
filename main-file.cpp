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
void saveDataToFile(const string& filename, float amounts[][2], string categories, string dates[], int currentIndex);
void calculateBalance(float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);
void addExpenses();
void viewExpenses();
void displayMenu();

double calculateMonthlySavings(const string months[], const double income[], const double expenses[], int numMonths, const string& targetMonth);
double calculateTotalSavings(const double income[], const double expenses[], int numMonths);

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
                addEntry(type, amount, category, date, amounts[][], categories[], 
                dates[], &currentIndex);
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

            case 5: {
                string targetMonth;
	           double income[];
               string months[MAX_MONTHS] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
          for(int i=0; i<12; i++){
    	  cout<<"Enter the income for month: "<<i+1;
    	    cin>>income[i];
    	    cout<<endl;
	} 
    int numMonths = 12; 
    cout<<"Enter the month for which you want to display the total savings: ";
    cin>>targetMonth;
    double monthlySavings = calculateMonthlySavings(months, income, expenses, numMonths, targetMonth);
    cout << "Savings for " << targetMonth << ": " << monthlySavings << endl;;
    double totalSavings = calculateTotalSavings(income, expenses, numMonths);
    cout << "Total Savings: " << totalSavings << endl;
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

void askUser (bool type, double amount, string category, string date) {
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

void viewExpenses(double amounts[][], string categories[], 
                string dates[], int &currentIndex) {
    int choice;
    if (currentIndex <=0)
    cout << "No Data entered yet." <<endl;
    
    else {
        cout << "Do you wish to view income (1), expense (0), or both (2)." << endl;
        cin >> choice;

    if (choice ==0) {
        for (int i=0; i<currentIndex; i++) {
            cout << "Index: " << i+1 << endl << "Category: " << categories[i] << endl; 
            cout << "Amount: " << amounts[i][] << endl << "Date Added: " << dates[i] <<endl;
            cout <<endl;
            }
        }
    }

}

void addEntry(bool type, double amount, string category, string date,
            double amounts[][2], string categories[], string dates[], int &currentIndex){
    /*This function stores the correct data: income or expense, category and date 
    2D array to store amount and its type (0 for expense and 1 for income) 
    1D array to store category and date*/
    // Check if there's space for more enteries
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

double calculateMonthlySavings(const string months[], const double income[], const double expenses[],
 int numMonths, const string& targetMonth) {
    for (int i = 0; i < numMonths; ++i) {
        if (months[i] == targetMonth) {
            return income[i] - expenses[i];
        }
    }
     cout << "Error: Month not found.\n";
    return 0.0;

    for (int i = 0; i < numMonths; ++i) {
        if (months[i] == targetMonth) {
            return income[i] - expenses[i];
        }
    }
     cout << "Error: Month not found.\n";
    return 0.0;
}



double calculateTotalSavings(const double income[], const double expenses[], int numMonths) {
    double totalSavings = 0.0;
    for (int i = 0; i < numMonths; ++i) {
        totalSavings += (income[i] - expenses[i]);
    }
    return totalSavings;
}
