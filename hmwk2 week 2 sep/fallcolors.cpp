#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //customber input
    char car_input;
    double days_rented;

    //model cases
    const char A = 'A';
    const char B = 'B';
    const char C = 'C';
    const char D = 'D';
    
    //cost output
    double cost = 0;

    //ask for customer input
    cout << "Which car type ( A, B, C, or D ) would you like to rent?" << endl;
    cin >> car_input;

    cout << "How many days would you like to rent this car?" << endl;
    cin >> days_rented;

    //cases

    switch (car_input) {
        case A:
            if (days_rented >= 0){
                cost = 1.09 * (100 + (days_rented * 15));
                cout << "Your bill total is $" << setprecision(2) <<  fixed << cost << endl; 
            } else {
                cout << "Please enter valid input." << endl;
            }
            break;
        case B:
            if (days_rented >= 0){
                cost = 1.09 * (150 + (days_rented * 20));
                cout << "Your bill total is $" << setprecision(2) <<  fixed << cost << endl; 
            } else {
                cout << "Please enter valid input." << endl;
            }
            break;
        case C:
            if (days_rented >= 0){
                cost = 1.09 * (200 + (days_rented * 25));
                cout << "Your bill total is $" << setprecision(2) <<  fixed << cost << endl; 
            } else {
                cout << "Please enter valid input." << endl;
            }
            break;
        case D:
            if (days_rented >= 0){
                cost = 1.09 * (250 + (days_rented * 30));
                cout << "Your bill total is $" << setprecision(2) <<  fixed << cost << endl; 
            } else {
                cout << "Please enter valid input." << endl;
            }
            break;
        default:
                cout << "Please enter valid input." << endl;
    }
    return 0;
}