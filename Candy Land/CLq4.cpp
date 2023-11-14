// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 4

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Candy
{
    string name;
    string description;
    double price;
    string candy_type;

};

vector<Candy> readCandy(string file_name, vector<Candy> candies)
{
    ifstream file(file_name);  // opens the file

    if (file.is_open()) 
    {
        string line;    // reading each line of file

        while (getline(file, line)) // reads line by line
        {
            Candy newCandy;             // creates a struct for a new candy struct to be made
            stringstream ss(line);      // all strings, will be read from file through ss
           
            if (!line.empty())          // some files have empty lines, checks for empty lines, will skip if empty
            {
                getline(ss, newCandy.name, '|');             // gets candy name from file
                getline(ss, newCandy.description, '|');      // gets candy description from file
                ss >> newCandy.price;                        // since price is a double and get line only takes strings, use ss
                ss.ignore();                                 // skips the deliminator ('|') 
                getline(ss, newCandy.candy_type);            // gets candy type from file

                candies.push_back(newCandy);                 // add the new candy structure to the vector
            }
            else
            {
                continue;               // loop will continue if line is empty
            }
        }

        file.close(); // closes file
    } 
    else // prints failure to open file
    {
        cout << "Failed to open file" << endl;
    }
    return candies; // returns candies vector in instance of failure and success in in opening file
}

void displayNewCandyStruct(vector<Candy> candies)
{
    for (int i = 0; i < candies.size(); i++)
    {
        cout << "Name: " << candies[i].name << ". " 
            << "Description: " << candies[i].description << ". " 
            << "Price: " << fixed << setprecision(2) << candies[i].price << ". " 
            << "Type: " << candies[i].candy_type
            << endl;
    }
}

int main() 
{
    vector<Candy> candies;                      // creates vector candies
    string candy_file;
    cout << "Enter file to read:" << endl;
    cin >> candy_file;
    candies = readCandy(candy_file, candies);  // calls for the readCandy function to be put in vector candies

    displayNewCandyStruct(candies);             // based on above information, display the candies

    return 0;
}