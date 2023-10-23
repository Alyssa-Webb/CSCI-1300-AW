// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 2

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>

using namespace std;

// finds average of temperatures: sum up the array values and divide by the size
double temperatureMean (double new_temperature[], const int temp_size)
{
    double sum = 0;
    // adds up all values in the array
    for (int i = 0; i < temp_size; i++)
    {
        sum = new_temperature[i] + sum;
    }

    // calculates & returns average 
    double average = (sum / temp_size);
    return average; 
}

// compute the difference between the largest and smallest number in the array
double temperatureRange(double new_temperature[], const int temp_size)
{
    double max = new_temperature[0];
    double min = new_temperature[0];
    double difference = 0;
    
    // find max value
    for (int i = 0; i < temp_size; i++)
    {
        if (new_temperature[i] >= max)
        {
            max = new_temperature[i];
        }
    }
    // find min value
    for (int i = 0; i < temp_size; i++)
    {
        if (new_temperature[i] <= min)
        {
            min = new_temperature[i];
        }
    }
    
    // calculates & returns difference 
    difference = max - min;
    return difference; 

}

// compute the difference between the last and current year's temperature readings and store the results in the delta array.
void temperatureDelta(double new_temperature[], double old_temperature[], double delta[], const int temp_size) 
{
    for (int i = 0; i < temp_size; i++)
    {
        delta[i] = old_temperature[i] - new_temperature[i];
        
    // testing: cout << delta[i] << endl;

    }
}

int main()
{	
    const int temp_size = 3;
    double old_temperature[temp_size] = {55.5, 77.7, 88.8};
    double new_temperature[temp_size] = {50.5, 67.2, 78.4};
    double delta[temp_size];  

    double tempMean = temperatureMean(new_temperature,temp_size); 
    cout << "Temperature Mean : " << tempMean << endl; 
    double tempRange = temperatureRange(new_temperature,temp_size); 
    cout << "Temperature Range : " << tempRange << endl; 
    temperatureDelta(new_temperature, old_temperature, delta, temp_size);
    return 0;
}