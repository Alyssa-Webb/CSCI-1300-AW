// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Vedant and Jason
// Question 4

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int purchaseTruck (int budget, int truck_model);

int main () 
{

int budget = 81350;
int truck_model;

    cout << "These are the trucks available for purchase: \n" 
        << "Truck model 1: Ford F-150. Price: $26,900 \n"
        << "Truck model 2: Dodge RAM 1500. Price: $21,400 \n"
        << "Truck model 3: Chevy Silverado. Price: $24,700 \n"
        << "Truck model 4: Toyota Tundra. Price: $31,200 \n" 
        << "Truck model 5: GMC Sierra 1500. Price: $28,300 \n" 
        << "Please enter a number from 1 to 5:" << endl;

// First Truck
    cin >> truck_model;
    
    budget = purchaseTruck (budget, truck_model);

// Second Truck
    cout << "Please enter a number from 1 to 5:" << endl;
    cin >> truck_model;

    budget = purchaseTruck (budget, truck_model);


// Third Truck

    if (budget > 31200) 
    {
        cout << "Please enter a number from 1 to 5:" << endl;
        cin >> truck_model;
    
        budget = purchaseTruck (budget, truck_model);
    }
    else 
    {
        return 0;
    }

}



int purchaseTruck (int budget, int truck_model)
{
    int new_budget;
   
    switch (truck_model)
    {
        case 1:
            new_budget = budget - 26900;
                
            if (budget < 26900) 
            {
                return 0;
            }
            else
            {
                cout << "Congratulations! You have purchased a Ford F-150" << endl;
            }
        
            break;
        
        case 2:
            new_budget = budget - 21400;
            
            if (budget < 21400) 
            {
                return 0;
            }
            else
            {
                cout << "Congratulations! You have purchased a Dodge RAM 1500" << endl;
            }

            break;
        
        case 3:
            new_budget = budget - 24700;

            if (budget < 24700) 
            {
                return 0;
            }
            else
            {
                cout << "Congratulations! You have purchased a Chevy Silverado" << endl;
            }

            break;
        case 4:
            new_budget = budget - 31200;
            
            if (budget < 31200) 
            {
                return 0;
            }
            else
            {
            cout << "Congratulations! You have purchased a Toyota Tundra" << endl;
            }

            break;
        case 5:
            new_budget = budget - 28300;
            if (budget < 28300) 
            {
                return 0;
            }
            else
            {
            cout << "Congratulations! You have purchased a GMC Sierra 1500" << endl;
            }

        break;

        default:
            cout << "Invalid input!" << endl;
            return budget;
            break;
    }

        return new_budget;
    

}



