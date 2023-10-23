#include <iostream>

using namespace std;

int main(){
    double base_one;
    double base_two;
    double height;
    
    double area;

    cout << "What is the length of one of the parallel sides?" << endl;
    cin >> base_one;


    cout << "What is the length of the other parallel side?" << endl;
    cin >> base_two;

    cout << "What is the height of the trapezoid?" << endl;
    cin >> height;

// calculate area of trapezoid 
    area = height * ((base_one + base_two) / 2);

//area output
    cout << "The trapezoid has an area of " << area << " units." << endl;

}

//Create a program that calculates the area of a trapezoid. 
// You should prompt the user for the two side lengths and the height.
// A trapezoid is a four-sided polygon with two parallel and two non-parallel sides. 
// The formula to calculate the area of a trapezoid is:
// area = 0.5 * (base_one + base_two) * height
// base_one is the length of one of the parallel sides
// base_two is the length of the other parallel side
// height is the distance between the two parallel side