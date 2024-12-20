#include <iostream>

using namespace std;

int main(){

    int choice;

    if (choice == 1){
        bool type;
            double amount;
            string category;
            string date;

            askUser(type, amount, category, date);
            saveDataToFile(file, type, amount, category, data);
            break;
    }

    else {
        loadDataFromFile(amounts, categories, dates)
        switch (choice){
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