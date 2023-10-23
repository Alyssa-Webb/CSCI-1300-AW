// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 2

#include <iostream>
#include <iomanip>
#include <string>

#include <cassert>

using namespace std;

int getMethod2ShiftAmount(string key1)
{
    int character_number = 0; // will be used to count characters
    int vowels_number = 0; // will be used to count vowels

    for (int i = 0; i < key1.length(); i++) 
    {
        char checking_char = key1[i]; // create variable that compares the 
        
        if (isalpha(checking_char)) // continues program only if the char is in the alphabet
        {
            if ((checking_char == 'a') || (checking_char == 'e') || (checking_char == 'i') || (checking_char == 'o') || (checking_char == 'u') || (checking_char == 'y')) // checks if vowels
            {
                vowels_number++; // increments if vowel is present
            }
        }
        
        character_number++; // increments each character it passes
    }

    return ((character_number + vowels_number) % 26); // returns the total between vowels and characters counted

}

main ()
{
assert (getMethod2ShiftAmount("hello world! this is a key") == 8);
assert (getMethod2ShiftAmount("aaaaaaaaaaaaa") == 0);
assert (getMethod2ShiftAmount("aeiou") == 10);
assert (getMethod2ShiftAmount("a") == 2);
assert (getMethod2ShiftAmount("a") == 2);
assert (getMethod2ShiftAmount("#") == 1);
assert (getMethod2ShiftAmount("g") == 8);
assert (getMethod2ShiftAmount("12345") == 5);
}