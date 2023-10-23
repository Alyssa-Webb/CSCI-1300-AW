// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Vedant and Jason
// Question 3

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int manageFeeder (int feeder, int daysSinceRefill);

int main ()
{
    int days_since_refill_one;
    int days_since_refill_two;
    int days_since_refill_three;


    cout << "How many days ago was feeder 1 filled?" << endl;
    cin >> days_since_refill_one;

        if (days_since_refill_one < 0) 
        {
            cout << "Invalid input!" << endl;
            return 0;
        }
    
            int refill_day_one = manageFeeder (1, days_since_refill_one);

    cout << "How many days ago was feeder 2 filled?" << endl;
    cin >> days_since_refill_two;

        if (days_since_refill_two < 0) 
        {
            cout << "Invalid input!" << endl;
            return 0;
        }

            int refill_day_two = manageFeeder (2, days_since_refill_two);

    
    cout << "How many days ago was feeder 3 filled?" << endl;
    cin >> days_since_refill_three;

        if (days_since_refill_three < 0) 
        {
            cout << "Invalid input!" << endl;
            return 0;
        }
            int refill_day_three = manageFeeder (3, days_since_refill_three);

    cout << "Feeder 1 will need to be filled in " << refill_day_one << " days, " << "feeder 2 will need to be filled in " << refill_day_two << " days, " << "and feeder 3 will need to be filled in " << refill_day_three << " days." << endl;
        

}

int manageFeeder (int feeder, int daysSinceRefill) 
{
    int temp_refill_day;
    
    

    switch (feeder) 
    {
        case 1:
            temp_refill_day = (21 - (daysSinceRefill*3)) / 3;
                if (temp_refill_day < 0)
                {
                    temp_refill_day = 0;
                } 
        break;

        case 2:
            temp_refill_day = (37 - (daysSinceRefill*2)) / 2;
                if (temp_refill_day < 0)
                {
                    temp_refill_day = 0;
                }     
        break;

        case 3:
            temp_refill_day = (17 - (daysSinceRefill*4)) / 4;
                if (temp_refill_day < 0)
                {
                    temp_refill_day = 0;
                } 
        break;

    }
    return temp_refill_day;


}