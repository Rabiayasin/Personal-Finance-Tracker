// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int MAX_SIZE = 100;

void addEntry(string type, float amount, string category, string date);
void askUser();
void saveDataToFile(const string& file, bool type, int amount, string category, string date, int currentIndex);
void calculateBalance(float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);
void addExpenses();
void viewExpenses();
void displayMenu();
void loadDataFromFile(const string &filename, float amounts[][2], string categories[], string datas[]);
double calculateMonthlySavings(const string months[], const double income[], const double expenses[], int numMonths, const string& targetMonth);
double calculateTotalSavings(const double income[], const double expenses[], int numMonths);


// All the functions:

int main() {

    bool type = 0;
    double amount = 0;
    string category = "";
    string data = "";
    int currentIndex;

    string file = "";
    // load data to File
    askUser(type, amount, category, data);
    saveDataToFile(file, type, amount, category, data, currentIndex);
    
    // Load data from file
    float amounts[][2] = {};
    string categories[] = {};
    string dates[] = {};

    loadDataFromFile(amounts, categories, dates);


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

void saveDataToFile(const string& file, bool type, int amount, string category, string date, int currentIndex){
    // open file for writing
    ofstream outFile(file);

    // check if file opened successfully 
    if (!outFile){
        cout<<"Error: COuld not open file for writing."<<endl;
        return;
    }

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


void loadDataFromFile(const string &filename, float amounts[][2], string categories[], string datas[]){
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
        if (index < 0 || index >= MAX_SIZE){
            cout << "Warning: Invalid index in file: " << index +1 << endl;
            continue;
        }

        // Store data into arrays
        amounts[index][0] = amount;
        types[index][1] = type;
        categories[index] = category;
        dates[index] = date;

    }
    inFile.close();
}


double calculateMonthlySavings(const string months[], const double income[], const double expenses[], int numMonths, const std::string& targetMonth) {
    for (int i = 0; i < numMonths; ++i) {
        if (months[i] == targetMonth) {
            return income[i] - expenses[i];
        }
    }
     cout << "Error: Month not found.\n";
    return 0.0;
}
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



