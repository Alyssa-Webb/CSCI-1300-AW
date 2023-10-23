#include <iostream>
#include <iomanip>

using namespace std;

double calculatePaintCost (double totalWallArea, char paint_grade)
{
    double paint_cost;

    switch (paint_grade)
    {
        case 'A':
            paint_cost = totalWallArea * 0.75;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;
            
        case 'B':
            paint_cost = totalWallArea * 1.25;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;

        case 'C':
            paint_cost = totalWallArea * 2.75;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;

        default:
            cout << "Please enter a valid input" << endl;
            return 0;
    }
    return paint_cost;
}

int main () {
    double area;
    char paint_grade;

    cout << "Enter area of the four walls (in sq ft)" << endl;
    cin >> area;

    cout << "Select the paint grade (A, B, or C)" << endl;
    cin >> paint_grade;

    if (area <= 0) {
            cout << "Please enter a valid input" << endl;
            return 0;
    } else
    {
        double totalPaintCost = calculatePaintCost (area, paint_grade);
    }
}




