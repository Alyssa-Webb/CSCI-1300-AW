// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Vedant and Jason
// Question 5

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;


double calculateDistance (double x1, double y1, double x2, double y2, int distance_type);


int main ()
{

    double distance_type;

    double x1;
    double y1;
    double x2;
    double y2;

    cout << "Enter distance type:" << endl;
    cin >> distance_type; 

    if ((distance_type < 0) || (distance_type > 2))
    {
        cout << "Invalid distance type!" << endl;
        return 0;
    
    }

    cout << "Enter x1:" << endl;
    cin >>  x1;

    cout << "Enter y1:" << endl;
    cin >>  y1;

    cout << "Enter x2:" << endl;
    cin >>  x2;

    cout << "Enter y2:" << endl;
    cin >> y2;

    double distance = calculateDistance (x1, y1, x2, y2, distance_type);

    cout << "The distance between the points is: " << setprecision(3) << fixed << distance << endl;

}


double calculateDistance (double x1, double y1, double x2, double y2, int distance_type)
{

double distance;

    switch (distance_type)
    {
        case 1:
            distance = (abs(x2 - x1)) + (abs(y2-y1));

        break;

        case 2:
            distance = (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 -y1) * (y2 -y1))));

        break;

        default:
            cout << "Invalid distance type!" << endl;
            return 0;
    }

    return distance; 

}