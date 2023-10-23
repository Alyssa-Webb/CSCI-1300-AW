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
    int user_input;     // stores input for menu (1-6)
    int method_input;   // stores the users chosen method (1-4)
    
    string key1;        // stores key1
    string key2;        // stores key2
    string message;     // stores the message the user wants to encrypt or decrypt
    string result;      // stores the result from encrypting/decrypting

    // determines if user met requirements to encrypt/decrypt a message
    bool k1_done = false;      // if key one has a valid value, evaluates true
    bool k2_done = false;      // if key two has a valid value, evaluates true
    bool m_done = false;       // if key method has a valid valie, evaluates true

do  // using a do-while will allow the menu to be shown until condition is met
{
    // menu shown to user, they can choose an input 1-6, where 6 terminates the program
    cout << "Please input 1-6 followed by enter to navigate the menu:\n" 
            << "1. Set Encryption Key 1\n"
            << "2. Set Encryption Key 2\n"
            << "3. Select Encryption Method\n"
            << "4. Encrypt Message\n"
            << "5. Decrypt Message\n"
            << "6. Exit Program"
            << endl;
    cin >> user_input;                      // stores input for the menu-oriented program
    
    // if user input is invalid  
    while (cin.fail() || user_input < 1 || user_input > 6) 
        // cin.fail becomes true when user_input is invalid, evaluates true
        // if user input is 0 or negative, invalid, evaluates true
        // if user input is beyond program limits (6), invalid, evaluates true
    { 
        cout << "Invalid input" << endl;    // outputs to the user that their input was invalid
        cin.clear();                        // buffer is cleared so that a new input can be stored
        cin.ignore(10000,'\n');             // ignores '\n' for x (1000) characters
        cin >> user_input;                  // cin was cleared, ask for user input again, loop will continue until input is valid
    }

    switch (user_input)
    {
        case 1: // set encryption key 1
        // input will be checked by the while loop
            cout << "Enter key:" << endl;   // prompts user to enter key1 string
            
            cin.ignore(10000,'\n');         // cin will ignore '\n'
            getline(cin, key1);             // assigns input without '\n' to key1

            while (key1.length() < 1)       // if the length of the string is less than one, prints invalid input and requests another input
            {
                cout << "Invalid key" << endl;  // informs user their input was not valid
                cout << "Enter key:" << endl;   // prompts to input another key
                getline (cin, key1);            // will take input and check validity
            }
    
            cout << "Successfully set encryption key1 to " << key1 << endl; // prints success for key1 value
            k1_done = true;

            break;

        case 2: // set encryption key 2
        // input will be checked by the while loop
            cout << "Enter key:" << endl; // prompts user to enter key1 string
            
            cin.ignore(10000,'\n');       // cin will ignore '\n'
            getline(cin, key2);           // assigns input without '\n' to key1

            while (key2.length() < 1)     // if the length of the string is less than one, prints invalid input and requests another input
            {
                cout << "Invalid key" << endl;  // informs user their input was not valid
                cout << "Enter key:" << endl;   // prompts to input another key
                getline (cin, key2);            // will take input and check validity
            }
    
            cout << "Successfully set encryption key2 to " << key2 << endl; // prints success for key2 value
            k2_done = true;

            break;


        case 3: // select method
        // user is given a menu of encryption techniques, must choose a valid input between (1,4)
        // input will be checked by the while loop
            cout << "Please input 1-4 to decide encryption technique.\n"
                 << "1. Method1 only (shift by 1) \n"
                 << "2. Method2 only (shift by first key)\n"
                 << "3. Method3 only (shift by both keys)\n"
                 << "4. Mix of Method1, Method2, Method3\n"
                 << endl;
            cin >> method_input;

            while (cin.fail() || method_input < 1 || method_input > 4) 
                // cin.fail becomes true when method_input is invalid, evaluates true
                // if user input is 0 or negative, invalid, evaluates true
                // if user input is beyond program limits (4), invalid, evaluates true
            { 
                cout << "Invalid input" << endl;    // outputs to the user that their input was invalid
                cin.clear();                        // buffer is cleared so that a new input can be stored
                cin.ignore(10000,'\n');             // ignores '\n' for x (1000) characters
                cin >> method_input;                // cin was cleared, ask for user input again, loop will continue until input is valid
            }

            cout << "Successfully set encryption type to " << method_input << endl; // prints success for method value
            m_done = true;

            break;


        case 4: // encrypt message
            if ((k1_done == false) || (k2_done == false) || (m_done == false ))
            {
                cout << "You cannot do this until you set both keys and choose an encryption method " << endl; // prints to the user they have not met all requirements to encrypt/decrypt
            }
            else
            {
                cout << "Enter your message to encrypt: " << endl;  // prompts user to enter their desired message for ENCRYPTION
                cin.ignore(10000,'\n');                             // ignores '\n' for x (1000) characters
                getline(cin, message);                              // input is used for var string message
                
                result = encryptMessage(message, method_input, key1, key2); // calls function using users input parameters
                cout << result << endl;
            }

            break;

        case 5: // decrypt message
            if ((k1_done == false) || (k2_done == false) || (m_done == false ))
            {
                cout << "You cannot do this until you set both keys and choose an encryption method " << endl; // prints to the user they have not met all requirements to encrypt/decrypt
            }
            else
            {
                cout << "Enter your message to decrypt: " << endl;  // prompts user to enter their desired message for DECRYPTION
                cin.ignore(10000,'\n');                             // ignores '\n' for x (1000) characters
                getline(cin, message);                              // input is used for var string message
                
                result = decryptMessage(message, method_input, key1, key2); // calls function using users input parameters
                cout << result << endl;
            }

            break;

        case 6: // terminates program
            cout << "Goodbye." << endl;     // prints "Goodbye." to the user before terminating

            break;                          // loop and therefore terminates the program
    }

} while (user_input != 6);           // while the program is not exited (input !=6) the program will run

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

