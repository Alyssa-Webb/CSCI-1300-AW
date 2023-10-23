#include <iostream>

using namespace std; 

int main (){
    double indoor = 10;
    double outdoor = 14;
    double hours;

    cout << "How many hours have passed?" << endl;
    cin >> hours;

//initial pool values added to the fill rate minus the leakage rate
    indoor = indoor + ((0.5 * hours) - (0.2 * hours));
    outdoor = outdoor + ((0.8 * hours) - (0.3 * hours));

    cout << "The indoor pool has " << indoor << " inches of water, and the outdoor pool has " << outdoor << " inches of water." << endl;
    
}

//You're in charge of maintaining a swimming pool with a minor leak.
// The pool has some water in it already and needs to be filled up. 
//However, due to the leak, the water level decreases slightly every hour at a constant rate. 
//Your goal is to create a program that helps you track the pool's water level over time.