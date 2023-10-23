#include <iostream>
#include <iomanip>

using namespace std;

double calculateWallArea (double length, double width) 
{
    double height = 10.0; // constant value

    double wall_length = 2*(length*height);

    double wall_width = 2*(width*height);

    double total_area = wall_width + wall_length;

    return total_area;

}

double calculatePaintCost (double wallArea, char paint_grade)
{
    double paint_cost;

    switch (paint_grade)
    {
        case 'A':
            paint_cost = wallArea * 0.75;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;
            
        case 'B':
            paint_cost = wallArea * 1.25;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;

        case 'C':
            paint_cost = wallArea * 2.75;
            cout << "The total cost to paint all four walls: $" << paint_cost << endl;
            break;

        default:
            cout << "Please enter a valid input" << endl;
            return 0;
    }
    return paint_cost;
}

double estimatePaintingTime(double area, char painter) 
{

double paintTime;
        
    switch (painter)
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
    char option;

    cout << "Choose an option \n" << "1. Calculate Exterior Wall Area \n" << "2. Calculate Paint Cost \n" << "3. Estimate Painting Time \n" << "4. Exit" << endl;
    cin >> option;

    switch (option) 
    {
        case 1: // area
        { 
            double length;
            cout << "Enter length of the base of the house (in ft)" << endl;
            cin >> length;

            double width;
            cout << "Enter width of the base of the house (in ft)" << endl;
            cin >> width;

            if (length <= 0) 
            {
                cout << "Please enter a valid input" << endl;

                return 0;
            }
            else if (width <= 0)
            {
                cout << "Please enter a valid input" << endl;

                return 0;
            }

            double totalWallArea = calculateWallArea (length, width);

            cout << "The total area of all the four walls: " <<  totalWallArea << " sq ft" << endl;
            break;
        }

        case 2: // paint cost
        {
            double paint_area;
            cout << "Enter area of the four walls (in sq ft)" << endl;
            
            char paint_grade;
            cin >> paint_area;

            cout << "Select the paint grade (A, B, or C)" << endl;
            cin >> paint_grade;

            if (paint_area <= 0) {
                cout << "Please enter a valid input" << endl;
                return 0;
            }       
            else
            {
                double totalPaintCost = calculatePaintCost (paint_area, paint_grade);
            }
            break;
        }

        case 3: // choose painter
        {
            double painter_area;
            cout << "Enter area of the four walls (in sq ft)" << endl;
            cin >> painter_area;

            char painter;
            cout << "Select a painter (W, X, Y or Z)" << endl;
            cin >> painter;

            if (painter_area <= 0) 
            {
                cout << "Please enter a valid input" << endl;
                return 0;
            } 
            else
            {
                double paintTime = estimatePaintingTime (painter_area, painter);
            }
            break;
        }

        case 4:
        {
            cout << "Thank you!" << endl;
            break;
        }

}
}