#include <iostream>
#include <iomanip>

using namespace std;

double calculateWallArea (double length, double width) 
{
    double height = 10.0; // constant value

    double wall_length = 2*(length*height);

    double wall_width = 2*(width*height);

    double total_area = wall_width + wall_length;

    return total_area * 1;

}



int main () 
{
double length;
double width;

cout << "Enter length of the base of the house (in ft)" << endl;
cin >> length;

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

    return 0;
}