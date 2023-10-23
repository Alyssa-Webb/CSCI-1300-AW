// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 4

#include <iostream>
#include <iomanip>
#include <string>

#include <cassert>

using namespace std;

// Method 1
char shiftChar(char c, int shift)
{
 
    if (isalpha(c)) // isalpha checks to see if the user input a real character
    {
        c = static_cast<int>(c); // converts the input character to its integer value

        while (shift < 0) // results in actual shift value, removes (-) value
        {
            shift += 26;
        }

        if ((c >= 97) && (c <= 122)) // lowercase alphabetic letters in ASCII
        {
            c = ((c - 97 + shift) % 26 + 97);

            return static_cast<char>(c); // casts ASCII value to char
        }
        else
        {
            return c; // will result in error, was not encrypted
        }
    }
    
    return c; // will result in error, was not encrypted
}


// Method 2

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

// Method 3 
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


char encryptChar(char c, int method_choice, string key1, string key2)
{
    int temp = 0; // creating temp variable to store integers from method 1 & 2

    char encrypted_message = c; // character that is being encrypted & returned

    switch (method_choice)
    {
        case 1: // Method 1
            encrypted_message = shiftChar (c, 1);
            
            break;

        case 2: // Method 2
            temp = (getMethod2ShiftAmount(key1));
            encrypted_message = shiftChar(c, temp);

            break;

        case 3: // Method 3
            temp = (getMethod3ShiftAmount (key1, key2));
            encrypted_message = shiftChar(c, temp);
            break;

        default: 
            cout << "Invalid encryption method" << endl;
            
            break;
    }
    return encrypted_message;
}

int main () 
{
    char c;
    int method_choice;
    string key1;
    string key2;

    cout << "Enter a letter to encrypt: " << endl;
    cin >> c;

    cout << "Enter key 1: " << endl;
    cin >> key1;

    cout << "Enter key 2: " << endl;
    cin >> key2;

    cout << "Select the Encryption Method to Use: \n"
         << "1) Method 1: Shift Right by 1. \n"
         << "2) Method 2: Shift Right by Key Formula. \n"
         << "3) Method 3: Shift Right by Mixed Key Formula.\n";

    cin >> method_choice;

    encryptChar (c, method_choice, key1, key2); 

    //assert (encryptChar ('#' , "key1", "key2", 2) == '#');
    //assert (encryptChar('G', "key1", "key2", 3) == 'G');
    //assert (encryptChar('r', "12345", "unused", 2) == 'w');
}