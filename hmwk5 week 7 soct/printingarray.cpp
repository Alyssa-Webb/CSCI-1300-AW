// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 1

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>

using namespace std;

void printCards (string card_names[], int size);
void printNums (int numbers[], int size);
void printSqRoot (double sq_root_nums[], int size);
void printASCII (char letters[], int size);

int main ()
{
// arrays
    string card_names[9] =  {"Ace", "Clubs", "Diamonds", "Hearts", "Spades", "Jack", "Queen", "King", "Joker"};
    double sq_root_nums[10] = {};
    int numbers[7] = {};
    char letters[52] = {};

    printCards(card_names, 9);
    printSqRoot(sq_root_nums, 10);
    printNums(numbers, 7); 
    printASCII(letters, 52);

    return 0;
}

// prints ASCII values
void printASCII (char letters[], int size)
{
    int upperCase = 64;
    int lowerCase = 96;
    
    for (int i = 0; i < size; i++)
    {
// A, B, C
    if (i % 2 == 0) {
        upperCase++;
        letters[i] = upperCase;
    }
// a, b, c
    else
    {
        lowerCase++;
        letters[i] = lowerCase;
    }

        cout << letters[i] << " " << endl;
    }
}

// prints card strings
void printCards (string card_names[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << card_names[i] << endl;  
    }
}

// prints square root values
void printSqRoot (double sq_root_nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // + 1 since index starts at 0, do not want sqrt(0)
        double sqrt_value = sqrt(i + 1);
        sq_root_nums[i] = sqrt_value;

        // ensures output is to 3 decimal values
        cout << setprecision(3) << fixed << sq_root_nums[i] << endl;
    }
}

// prints values divisible by 7
void printNums (int numbers[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int n = 50; n <= 100; n++)
        {
            if(n % 7 == 0)
            {
                numbers[i] = n; 
                cout << n << endl; 
            }
            i++;
        }
    }
}