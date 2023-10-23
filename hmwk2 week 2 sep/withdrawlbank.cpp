#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double bank_balance = 1000.00;
    double desired_withdrawl;
    
    cout << "Enter the amount to be withdrawn from your bank account:\n";
    cin >> desired_withdrawl;
    
    double withdrawl_test = bank_balance - desired_withdrawl;
    
    if (desired_withdrawl < 0.01) {
        cout << "Invalid input. Withdrawn amount must be a non-negative value.";
   
    } else if (withdrawl_test < 100.00) {
        cout << "Transaction Failed!";
        
    } else {
        cout << "Transaction Successful! " << "You're balance is $";
        cout << setprecision(2) <<  fixed << withdrawl_test;
        
    }
    return 0;
}
