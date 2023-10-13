// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 8

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;

// Function Prototypes
char shiftChar(char c, int shift);
int getMethod2ShiftAmount(string key1);
int getMethod3ShiftAmount (string key1, string key2);
string decryptMessage(string message, int method_choice, string key1, string key2);
string encryptMessage(string message, int method_choice, string key1, string key2);

// Main
int main ()
{

bool program_running = true; // while true, program continues, when false, program terminates

while (program_running) { // while the program is not exited, it will continue to run
    int user_input = 0;
    int method_input = 0;

    string key1 = "";
    string key2 = "";
    string message = "";

    bool key1_done = false; // setting key1 to false ensures that user has met requirements to encrypt/decrypt a message
    bool key2_done = false; // setting key2 to false ensures that user has met requirements to encrypt/decrypt a message
    bool encryption_done = false; // setting encryption to false ensures that user has met requirements to encrypt/decrypt a message
    
    while (user_input < 1 || user_input > 6)
    {
    cout << "Please input 1-6 followed by enter to navigate the menu:\n"
            << "1. Set Encryption Key 1\n"
            << "2. Set Encryption Key 2\n"
            << "3. Select Encryption Method\n"
            << "4. Encrypt Message\n"
            << "5. Decrypt Message\n"
            << "6. Exit Program"
            << endl;
    cin >> user_input;
    }

    switch (user_input) 
    {
        case 1: // Encryption Key 1
            while (!key1_done)
            {
                cout << "Enter key:" << endl;
                cin >>  key1;
                
                if (key1.length() > 1)
                {
                    cout << "Successfully set encryption key1 to " << key1 << endl; 
                    key1_done = true;
                }
                else 
                {
                    cout << "Invalid key" << endl;
                    cin.clear();
                }

            }
            key1_done = true;
            break;
        case 2: // Encryption Key 2
            while (!key2_done)
            {
                cout << "Enter key:" << endl;
                cin >>  key2;
                
                if (key2.length() > 1)
                {
                    cout << "Successfully set encryption key2 to " << key2 << endl; 
                    key2_done = true;
                }
                else 
                {
                    cout << "Invalid key" << endl;
                    cin.clear();
                }
            }
            key2_done = true;
            break;
        case 3: // Encryption Method
            while (!encryption_done)
            {
                cout << "Please input 1-4 to decide encryption technique.\n"
                        << "1. Method1 only (shift by 1) \n"
                        << "2. Method2 only (shift by first key)\n"
                        << "3. Method3 only (shift by both keys)\n"
                        << "4. Mix of Method1, Method2, Method3\n"
                        << endl;
                    cin >> method_input;

                if ((method_input != 1) && (method_input != 2) && (method_input != 3) && (method_input != 4))
                {
                    cout << "Invalid encryption choice" << endl;
                    cin.clear();
                }
                else 
                {
                    cout << "Successfully set encryption type to " << method_input << endl;
                    encryption_done = true;
                }
            }
            encryption_done = true;
            break;
        case 4: // Encrypt Message
            if (!key1_done && !key2_done && !encryption_done)
            {
                cin.ignore(1000, '\n');
                cin.clear();
                cout << "Enter your message to encrypt:" << endl;
                getline(cin, message);
                cout << encryptMessage(message, method_input, key1, key2) << endl;
            }
            else
            {
                cout << "You cannot do this until you set both keys and choose an encryption method" << endl;
            }
            break;
            
        case 5: // Decrypt Message
            if (!key1_done && !key2_done && !encryption_done )
            {   
                cin.ignore(1000, '\n');
                cin.clear();
                cout << "Enter your message to encrypt:" << endl;
                getline(cin, message);
                cout << decryptMessage(message, method_input, key1, key2) << endl;
            }
            else
            {
                cout << "You cannot do this until you set both keys and choose an encryption method" << endl;
            }
            break;
        case 6: // Exit Program
            cout << "Goodbye." << endl;
            program_running = false;
            break;
    }
}
}

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

// Decrypt Message
string decryptMessage(string message, int method_choice, string key1, string key2)
{
    int temp = 0;
    string decrypted_message = message; // Initialize with the original message

    switch (method_choice)
    {
        case 1: // Method 1
            for (int i = 0; i < message.length(); i++)
            {
                decrypted_message[i] = shiftChar(message[i], -1); // places shifted characters in decrypted_message to create full string
            }
            break;

        case 2: // Method 2
            temp = getMethod2ShiftAmount(key1);
            for (int i = 0; i < message.length(); i++)
            {
                decrypted_message[i] = shiftChar(message[i], -temp); // places shifted characters in decrypted_message to create full string
            }
            break;

        case 3: // Method 3
            temp = getMethod3ShiftAmount(key1, key2);
            for (int i = 0; i < message.length(); i++)
            {
                decrypted_message[i] = shiftChar(message[i], -temp); // places shifted characters in decrypted_message to create full string
            }
            break;

        case 4: // Method 4: 
            for (int i = 0; i < message.length(); i++)
            {
                if (isalpha(message[i]))
                {
                    int method_4_choice = (i % 3) + 1; // chooses method based on value of i
                    int temp;

                    if (method_4_choice == 1)
                    {
                        temp = 1;   // Method 1
                    }
                    else if (method_4_choice == 2)
                    {
                        temp = getMethod2ShiftAmount(key1); // Method 2
                    }
                    else if (method_4_choice == 3)
                    {
                        temp = getMethod3ShiftAmount(key1, key2); // Method 3
                    }

                    decrypted_message[i] = shiftChar(message[i], -temp); // places shifted characters in decrypted_message to create full string
                }
            }
            break;

        default:
            cout << "Invalid decryption method" << endl;
            break;
    }
    return decrypted_message;
}

// Encrypt Message
string encryptMessage(string message, int method_choice, string key1, string key2)
{
    int temp = 0;
    string encrypted_message = message; // Initialize with the original message

    switch (method_choice)
    {
        case 1: // Method 1
            for (int i = 0; i < message.length(); i++)
            {
                encrypted_message[i] = shiftChar(message[i], 1); // places shifted characters in encrypted_message to create full string
            }
            break;

        case 2: // Method 2
            temp = getMethod2ShiftAmount(key1);
            for (int i = 0; i < message.length(); i++)
            {
                encrypted_message[i] = shiftChar(message[i], temp); // places shifted characters in encrypted_message to create full string
            }
            break;

        case 3: // Method 3
            temp = getMethod3ShiftAmount(key1, key2);
            for (int i = 0; i < message.length(); i++)
            {
                encrypted_message[i] = shiftChar(message[i], temp); // places shifted characters in encrypted_message to create full string
            }
            break;

        case 4: // Method 4: 
            for (int i = 0; i < message.length(); i++)
            {
                if (isalpha(message[i]))
                {
                    int method_4_choice = (i % 3) + 1; // chooses method based on value of i
                    int temp;

                    if (method_4_choice == 1)
                    {
                        temp = 1;   // Method 1
                    }
                    else if (method_4_choice == 2)
                    {
                        temp = getMethod2ShiftAmount(key1); // Method 2
                    }
                    else if (method_4_choice == 3)
                    {
                        temp = getMethod3ShiftAmount(key1, key2); // Method 3
                    }

                    encrypted_message[i] = shiftChar(message[i], temp); // places shifted characters in encrypted_message to create full string
                }
            }
            break;

        default:
            cout << "Invalid encryption method" << endl;
            break;
    }
    return encrypted_message;
}
