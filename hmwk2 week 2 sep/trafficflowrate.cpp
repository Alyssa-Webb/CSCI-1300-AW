#include <iostream>

using namespace std;

int main() 
{
    // declare all the variables
    int traffic_flow_rate;

    // prompt the user & get their input
    cout << "What is the traffic flow rate on the highway?" << endl;
    cin >> traffic_flow_rate;

    // input validation: traffic flow rate on the highway must be positive
    if (traffic_flow_rate <= 0) // EDIT THIS LINE
    {
        cout << "Invalid traffic flow rate." << endl;
        return 0;
    }

    // decide if it's possible to reach the concert on time based on traffic flow rate
    if (traffic_flow_rate >= 800) // EDIT THIS LINE
    {
        cout << "You're gonna make it to the concert on time." << endl;
    }
    else
    {
        cout << "You're gonna be late to the concert." << endl;
    }

    return 0;
}