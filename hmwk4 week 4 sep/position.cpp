#include <iostream>
#include <string>
using namespace std;

string composeMessage(string first_name, string last_name, char position);

int main()
{
    //Declare variables
    string first_name, last_name;
    char position;

    //Capture user input
    cout << "What is your first name?" << endl;
    cin >> first_name;
    cout << "What is your last name?" << endl;
    cin >> last_name;
    cout << "What is your position? Enter P for passenger, C for captain, E for engineer, and N for navigator:" << endl;
    cin >> position;

    string message = composeMessage (first_name, last_name, position);
    cout << message << endl;

}

string composeMessage (string first_name, string last_name, char position) 
{
string message;
    switch (position) 
        {
            case 'P':
                message = "Welcome Aboard " + first_name + " " + last_name + "! The passenger rooms are thru the third door on the right";
                break;
            case 'C':
                message = "Welcome Aboard " + first_name + " " + last_name + "! The captain's quarters are up the stairs on the left";
                break;
            case 'E':
                message = "Welcome Aboard " + first_name + " " + last_name + "! The engine rooms are below deck down the second aft stairway";
                break;
            case 'N':
                message = "Welcome Aboard " + first_name + " " + last_name + "! The cartography chamber is up the stairs on the bow";
                break;
            default:
                message = "Invalid position!";
                break;
        }
    return message;

}