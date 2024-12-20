// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

// Global variables or constants
int MAX_ENTRIES = 100;

// All the functions:

void addEntry (bool type, double amount, string category, string date, double amounts[][2], string categories[], string dates[], int &currentIndex);
void askUser (bool& type, double& amount, string& category, string& date);
void saveDataToFile (string& filename, bool type, double amount, string category, string date, int currentIndex);
void loadDataFromFile (string &filename, double amounts[][2], string categories[], string dates[]);
void calculateBalance (float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);
void addExpenses (bool type, double amount, string category, string date, double amounts[][2], string categories[], string dates[], int &currentIndex);
void viewExpenses (double amounts[][2], string categories[], string dates[], int currentIndex);
void viewExpensesCategorically (string categories[], double amounts[][2], int currentIndex);
void calculateTotalSavings (double amounts[][2]);
void checkExpensesByDate (string dates[], double amounts[][2], string targetDate);
void displayMenu();

// All the functions:
int main() {

    bool type = 0;
    double amount = 0;
    string category = "";
    string date = "";

    string file = "file.txt";
    
    int choice;
    string categories[MAX_ENTRIES] = {}; 
    double amounts[MAX_ENTRIES][2]= {};
    string dates[MAX_ENTRIES] = {};
    int currentIndex = 0;

    while (true) {
        displayMenu();
        cout << "Enter the operation you want to add: ";
        cin >> choice;
        if (choice == 1){
            askUser(type, amount, category, date);
            saveDataToFile(file, type, amount, category, date, currentIndex);
        }  
        else if(choice==6){
            cout<<"Exiting program successfully!"<<endl;
            break;
        } 
        else {
        loadDataFromFile(file, amounts, categories, dates);
            if (choice == 2){
                viewExpenses(amounts, categories, dates, currentIndex);
            }
                
            else if (choice == 3){
                viewExpensesCategorically(categories, amounts, currentIndex);
            }
            else if (choice == 4) {
                string targetMonth;
	            double income[] = {};
             //function for calculating total savings
                calculateTotalSavings(amounts);
            }
            else if (choice == 5) {
                string targetDate;
                cout<<"Enter the date to check expenses (dd-mm-yy): ";
                getline(cin, targetDate);
                checkExpensesByDate(dates, amounts, targetDate);
            }
            else {
                cout<<"Invalid choice! Option not available! "<<endl;
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
    cout << "6. Exit the program!"<<endl;
}

void askUser (bool &type, double &amount, string &category, string &date) {
    cout << "Enter the type of entry (1 for income, 0 for expense)" <<endl;
    cin >> type;
    cout << "Enter the amount: " <<endl;
    cin >> amount;
    cout << "Enter the category of the amount: (Food, Electricity, School Bills etc)" <<endl;
    getline(cin, category);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the date of the expenditure: " <<endl;
    getline (cin, date);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void viewExpenses(double amounts[][2], string categories[], 
                string dates[], int currentIndex) {
    int choice;
    if (currentIndex < 0){
        cout << "No Data entered yet." <<endl;
    }
    else {
        cout << "Do you wish to view income (1), expense (0), or both (2)." << endl;
        cin >> choice;
    }
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
                cout << "Amount: " << amounts[i][0] << endl << "Date Added: " << dates[i] <<endl;
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
                cout << "Amount: " << amounts[i][0] << endl << "Date Added: " << dates[i] <<endl;
                cout <<endl;
            }
        }
    }
    else{
        cout << "Choice entered is not valid!" <<endl;
    }
    
}


void viewExpensesCategorically (string categories[], double amounts[][2], int currentIndex) {
    string enteredCategory;
    cout << "Enter the category you want to see the expenses of: ";
    getline(cin, enteredCategory);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<currentIndex; i++) {
    if (enteredCategory == categories[i])
        if  (amounts[i][1] == 0)
        cout << "Category: " << categories[i] << endl << "Amount: " << amounts[i][0] <<endl;
    }
}

void saveDataToFile(string& file, bool type, double amount, string category, string date, int currentIndex){
    // open file for writing
    ofstream outFile;
    outFile.open(file, ios::app);

    // check if file opened successfully 
    if (!outFile){
        cout<<"Error: COuld not open file for writing."<<endl;
        return;
    }
    
    currentIndex++;
    // Write each entry into the file
    outFile << currentIndex << ","  
                << amount << ","
                << type << ","
                << category << ","
                << date << endl;
    
    // close the file
    outFile.close();
    cout << "Data saved successfully to file: " << file <<endl;
}

void loadDataFromFile(string &filename, double amounts[][2], string categories[], string dates[]){
    ifstream inFile(filename);

    // Check if file opened successfully
    if (!inFile){
        cout << "Error: Could not open file for reading." << endl;
        return;
    }
    string line;
    while (getline(inFile, line)){
        stringstream ss(line);
        string indexStr, amountStr, typeStr, category, date;
        
        // Parse the line into components
        getline(ss, indexStr, ',');
        getline(ss, amountStr, ',');
        getline(ss, typeStr, ',');
        getline(ss, category, ',');
        getline(ss, date, ',');

        // Convert strings to other types
        int index = stoi(indexStr) - 1; // convert to 0 based index
        float amount = stof(amountStr);
        float type = stof(typeStr);

        // Check for valid index range
        if (index < 0 || index >= MAX_ENTRIES){
            cout << "Warning: Invalid index in file: " << index +1 << endl;
            continue;
        }

        // Store data into arrays
        amounts[index][0] = amount;
        amounts[index][1] = type;
        categories[index] = category;
        dates[index] = date;
    }
    inFile.close();
    cout << "Data loaded successfully." << endl;
}

void calculateTotalSavings(double amounts[][2]){
    double totalSavings, income, expense;
    for (int i=0; i<MAX_ENTRIES; i++){
        if (amounts[i][1] == 1){
            income += amounts[i][0]; 
        }
        else if (amounts[i][1] == 0){
            expense += amounts[i][0];
        }
    }
    totalSavings = income - expense;
    cout<<"Your total savings are: $"<<totalSavings<<"!"<<endl;
}

void checkExpensesByDate(string dates[], double amounts[][2], string targetDate){
    bool found = false;

    cout<<"Expense for date: "<<targetDate<<endl;
    for(int i=0; i<MAX_ENTRIES; i++){
        if(dates[i]==targetDate){
            cout<<"Amounts: $ "<<amounts[i][0]<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"No expenses for given date! "<<endl;
    }
}