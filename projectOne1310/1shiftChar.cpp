#include <iostream>
#include <iomanip>
#include <string>

#include <cassert>

using namespace std;

char shiftChar(char c, int shift)
{
 
    if (isalpha(c)) // isalpha checks to see if the user input a real character
    {
        c = static_cast<int>(c); // converts the input character to its integer value

        while (shift < 0) // results in actual shift value
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

main () 
{
assert (shiftChar ('a', 3) == 'd'); 
assert (shiftChar ('b', 3) == 'e'); 
assert (shiftChar ('a', -1) == 'z'); 
assert (shiftChar ('a', 100) == 'w'); 
assert (shiftChar ('a', -100) == 'e'); 
assert (shiftChar ('c', -7) == 'v'); 
assert (shiftChar (';', -7) == ';'); 
}
