#include <iostream>

using namespace std;

int main() {
   int windspeed;
   double temp;
   
    cout << "What is tomorrow's temperature looking like?" << endl;
    cin >> temp;
   
    cout << "What is tomorrow's wind speed looking like?" << endl;
    cin >> windspeed;
    
    
    if ((temp < 0) || (windspeed < 0)) {
        cout << "Please enter valid input.";
        
    } else if ((20 <= temp) && (temp <= 30) && (windspeed <= 50)) {
        cout << "The weather conditions are ideal for skiing tomorrow." << endl;
        
    } else {
        cout << "The weather conditions are not ideal for skiing tomorrow." << endl; 
}
return 0;
}
    