// Country Names
// This question may require the use of file streams, loops, and vectors.
// Write a C++ program to read a file of country names and print them to the console in the same order as they appear in the file.

// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 1

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void listCountries(string filename)
{
    // initialize variables
    ifstream file(filename); // opens a file // opens "countries_1.txt"
    vector<string> countries;

    if(file.is_open())
    {
        // Fill in the blank below with code to read from file and store in the countries vector
        string country;                            // this will store the entire line of the file
        while (getline(file, country))             // while loop continues until the end of the file is reached
        {
            countries.push_back(country);          // push_back command puts the file at the end of the vector {..., ..., (insert push_back)}
                                                // line is used as it stores the whole line as a string rather than singularly 

                                                // initial code: 
                                                    // ifstream file("countries_1.txt"); // this is one way of taking in data
                                                    // file >> countries;                // and storing it in a file, but it only stored the "The" in the The USA, rather than "The USA"
        }

        cout << "List of countries in the file are" << endl;    
        for(int i = 0; i < int(countries.size()); i++)
        {
            cout << countries.at(i) << endl;
        }
    }
    else
    {
        cout << "Failed to open file" << endl;
    }
    file.close();
}

int main()
{
    string filename;    
    cout << "Enter countries filename" << endl;
    cin >> filename;
    listCountries(filename);
    return 0;
}