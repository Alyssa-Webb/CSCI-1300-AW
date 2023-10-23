// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 3

#include <iostream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

// finds the most popular word in an array 
// and print the most popular word, 
// its frequency (how often it pops up), 
// and the indices (index) where you found it

void mostPopularWord(string words[], const int word_size)
{
    // will track the most frequent word
    int pop_frequency = 0;
    string pop_word = "";

    // traverses the list
    for (int i = 0; i < word_size; i++)
    {  
        string current_word = words[i];
        // temporarily stores the frequency of a word,
        // resets each (outer) loop
        int tempf = 0;
        
    // traverses comparing the entire list to only index i in the first traversal
        for (int j = 0; j < word_size; j++)
        {
            if (words[j] == current_word)
            {
                tempf++;
                
                // if the word currently being compared appears more than the previous element,
                // the element is replaced with the newly frequent word
                if (tempf >= pop_frequency)
                {
                    pop_frequency = tempf;
                    pop_word = words [i];
                }
            }
        }

    }
    cout << "The most popular word : " << pop_word << endl;
    cout << "Frequency : " << pop_frequency << endl;
    
    cout << "Found at pos : " << endl;
    // finds the index locations of the pop_word
    for (int i = 0; i < word_size; i++)
    {
        if (words[i] == pop_word)
        {
            cout << i << endl;
        }
    }       

}

int main()
{
    const int WORDS_SIZE = 6;
    string words[WORDS_SIZE] = {"apple", "apple", "foo", "bar", "apple", "code"};

    mostPopularWord(words, WORDS_SIZE); 
    
   

    return 0;
}