// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

// Global variables or constants
int MAX_ENTRIES = 100;

// All the functions:

void addEntry(string type, float amount, string category, string date);
void diplayMenu();


int main(){

    return 0;
}


void addEntry(bool type, float amount, string category, string date,
            float amounts[][2], string categories[], string dates[], int &currentIndex){
    /*This function stores the correct data: income or expense, category and date 
    2D array to store amount and its type (0 for expense and 1 for income) 
    1D array to store category and date*/

    // convert bool type into float
    float type = (type == true) ? 1 : 0;

    // store the data in the arrays
    float amounts[MAX_ENTRIES][2] // amounts and their type
    string categories[MAX_ENTRIES] = category;
    string dates[MAX_ENTRIES] = date;





}