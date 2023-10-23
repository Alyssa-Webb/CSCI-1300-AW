// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 3

#include <iostream>
#include <iomanip>
#include <string>

#include <cassert>

using namespace std;

int getMethod3ShiftAmount (string key1, string key2)
{
    int same_letter_count = 0;

    if (key1.length() > key2.length()) // key1 has longer string
    {
        for (int i = 0; i < key1.length(); i++) // traverses the larger string
        {
            char checking_one = key1[i]; // prioritizes first string because it is longer
            
            for (int j= 0; j < key2.length(); j++) // traverses the smaller and compares each character in key2 to the indexed value in key1
            {
                char checking_two= key2[j];
                if (checking_two == checking_one)
                {
                    same_letter_count++;
                }

            }
        }
    }

    else // key2 has longer string
    {
        for (int i = 0; i < key2.length(); i++) // traverses the larger string
        {
            char checking_one = key2[i]; // prioritizes second string because it is longer
            
            for (int j= 0; j < key1.length(); j++) // traverses the smaller and compares each character in key2 to the indexed value in key1
            {
                char checking_two= key1[j];
                if (checking_two == checking_one)
                {
                    same_letter_count++;
                }
            }
        }
    }
    return ((same_letter_count) % 26);
}



main ()
{
assert (getMethod3ShiftAmount("hi", "ho") == 1);
assert (getMethod3ShiftAmount("lpl pl", "ppyyll") == 10);
assert (getMethod3ShiftAmount("hi", "billy") == 1);
assert (getMethod3ShiftAmount("qwertyuiopasdfghjklzxcvbnm;", "qwertyuiop;asdfghjklzxcvbnm") == 1);
assert (getMethod3ShiftAmount("disco", "monkey") == 1);
assert (getMethod3ShiftAmount("key one", "other key") == 8);
}