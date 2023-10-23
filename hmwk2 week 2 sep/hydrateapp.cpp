#include <iostream>

using namespace std;

int main() {
    // goals and remaining water to drink for the day
    double water_goal = 64;
    double remaining_oz;
    // user input for how much water they drank today
    double water_drank;

    cout << "How much water have you drank today?" << endl;
    cin >> water_drank;

    // remaining water to drink for the day
    remaining_oz = water_goal - water_drank;

    // water intake updates
    if (water_drank <= 32) {
        cout << "You are very, very dehydrated! Get that water in! You have " << remaining_oz << " fl oz left to drink." << endl;
    } else if ((water_drank > 32) || (water_drank < 64)) {
        cout << "You are doing great, but youre still halfway to your goal! Get that water in! You have " << remaining_oz << "fl oz left to drink." << endl; 
    } else {
        cout << "You have hit your goal for the day! Great job getting hydrated!" << endl;
}
return 0;

}