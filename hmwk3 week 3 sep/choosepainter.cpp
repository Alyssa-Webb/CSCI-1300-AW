#include <iostream>
#include <iomanip>

using namespace std;

double estimatePaintingTime(double area, char painter) 
{

double paintTime;
        
    switch (area, painter)
    {
        case 'W':
            paintTime = (12 * (area/5))/60;
            cout << "The time taken to paint all four walls by painter " << painter << ": " << paintTime << " hours" << endl;
            break;

        case 'X':
            paintTime = (10 * (area/3))/60;
            cout << "The time taken to paint all four walls by painter " << painter << ": " << paintTime << " hours" << endl;
            break;

        case 'Y':
            paintTime = (5 * (area/2))/60;
            cout << "The time taken to paint all four walls by painter " << painter << ": " << paintTime << " hours" << endl;
            break;

        case 'Z':
            paintTime = (15 * (area/7))/60;
            cout << "The time taken to paint all four walls by painter " << painter << ": " << paintTime << " hours" << endl;
            break;

        default:
            cout << "Please enter a valid input" << endl;
            return 0;
            break;
    }
    return paintTime;
}


int main () 
{
    double area;
    char painter;
    
    cout << "Enter area of the four walls (in sq ft)" << endl;
    cin >> area;

    cout << "Select a painter (W, X, Y or Z)" << endl;
    cin >> painter;

    if (area <= 0) {
            cout << "Please enter a valid input" << endl;
            return 0;
    } else
    {
        double paintTime = estimatePaintingTime (area, painter);
    }

    return 0;
}