#include <iostream>

using namespace std;

int main() {
// customer input
    double customer_budget;
    char customer_seat;

// seat options (green, blue, purple, orange)
    const char G = 'G';
    const char B = 'B';
    const char P = 'P';
    const char O = 'O';

// budget question
    cout << "What is your budget?" << endl;
    cin >> customer_budget;

// seat question 
    cout << "Which of these seats would you like to take (G, B, P or O)?" << endl;
    cin >> customer_seat;

// comparing budget and seat to price
switch (customer_seat) {
    case G:
        if (customer_budget < 0) {
            cout << "Please enter valid input." << endl;

        } else if (customer_budget >= 1065.15) {
            cout << "Yes, this seat is within your budget!" << endl;

        } else  {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
        break;

    case B:
        if (customer_budget < 0) {
            cout << "Please enter valid input." << endl;
            
        } else if (customer_budget >= 1340.96) {
            cout << "Yes, this seat is within your budget!" << endl;

        } else  {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
        break;

    case P:
        if (customer_budget < 0) {
            cout << "Please enter valid input." << endl;
            
        } else if (customer_budget >= 1684.29) {
            cout << "Yes, this seat is within your budget!" << endl;

        } else  {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
        break;

    case O:
        if (customer_budget < 0) {
            cout << "Please enter valid input." << endl;
            
        } else if (customer_budget >= 1950.33) {
            cout << "Yes, this seat is within your budget!" << endl;

        } else  {
            cout << "Sorry, this seat is outside your budget." << endl;
        }
        break;

    default:
        cout << "Please enter valid input." << endl;
        break;

    }
    return 0;
}

