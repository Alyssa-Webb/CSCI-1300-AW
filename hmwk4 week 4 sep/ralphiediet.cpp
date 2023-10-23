// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Vedant and Jason
// Question 6

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double calculateAndDisplayDiet (double amount_fed, int day_today);

int main () 
{
    int day_today;
    double amount_fed;

    cout << "What day is it today? Enter a number from 0 to 6:" << endl;
    cin >> day_today;

    if ((day_today < 0) || (day_today > 6) )
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    cout << "How much was Ralphie fed yesterday? Enter an amount in MCals:" << endl;
    cin >> amount_fed;

    if (amount_fed < 0)
    {
        cout << "Invalid input!" << endl;
        return 0;
    }

    calculateAndDisplayDiet (amount_fed, day_today);

}


double calculateAndDisplayDiet (double amount_fed, int day_today) 
{
    double ralphie_diet;
    double least_eat;
    double most_eat;

    switch (day_today) 
    {
        case 0: // no game
            ralphie_diet = amount_fed + 12.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 12.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
            break;
        case 1: // no game
            ralphie_diet = amount_fed + 12.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 12.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
                break;


        case 2: // game
            ralphie_diet = amount_fed + 16.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 16.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
                break;    

        case 3: // no game
            ralphie_diet = amount_fed + 12.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 12.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
                break;


        case 4: // no game
            ralphie_diet = amount_fed + 12.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 12.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
                break;


        case 5: // game
            ralphie_diet = amount_fed + 16.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 16.5;
                    most_eat = 35 - amount_fed;
                    cout << setprecision(2) << fixed << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat << " MCals of food today." << endl;
                }
                break;    


        case 6: // game
            ralphie_diet = amount_fed + 16.5;
                if (ralphie_diet > 35)
                {
                    cout << "Ralphie was fed too much yesterday!" << endl;
                    return 0;
                }
                else
                {
                    least_eat = 16.5;
                    most_eat = 35 - amount_fed;
                    cout << "Ralphie should be fed at least " << least_eat << " and at most " << most_eat  << " MCals of food today." << endl;
                }
                break;    

    }
    return 0;

}

