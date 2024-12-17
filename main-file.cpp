// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

//Hey this is Rabia Yasinnn

// Global variables or constants
int MAX_ENTRIES = 100;

// All the functions:

void addEntry(string type, float amount, string category, string date);
void diplayMenu();
void askUser();
void saveDataToFile(const string& filename, float amounts[][2], string categories, string dates[], int currentIndex);
void calculateBalance(float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);

// All the functions:

 main


int main(){

    return 0;

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

