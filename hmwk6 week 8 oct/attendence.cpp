// Museum Attendence
// This question may require the use of file streams, loops, and arrays.

// Before leaving, the teachers wanted to compare the two lists to make sure no student was left behind. 
// Write a C++ program to help them do this quickly and easily. 
// Your program compares the two lists and reports if any student is still inside the museum.


// compares two files and prints the names of students
// names of students not yet on the bus


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void compareAttendanceSheet(string first_attendence_files, string second_attendence_files);

int main ()
{



}

void compareAttendanceSheet(string first_attendence_files, string second_attendence_files)
{
    ifstream file(first_attendence_files);      // opens initial attendence
    ifstream file(second_attendence_files);     // opens leaving attendence
    
    vector<string> attendence_1;                // vector to store intital attendence
    vector<string> attendence_2;                // vector to store leaving attendence
    vector<string> unaccounted_for;             // vector for kids left behind

    string name = "";               // names of students, stores full line from file


    if(file.is_open())
    {   
        while (getline(file, name))             // while loop continues until the end of the file is reached
        {
            attendence_1.push_back(name);          // push_back command puts the file at the end of the vector
            attendence_2.push_back(name);          // does so for each students name in the file
        }


        cout << "List of countries in the file are" << endl;    
        for(int i = 0; i < int(attendence_1.size()); i++)
        {
            for (int j = 0; i < int(attendence_2.size()); j++)
            {
                if (name[i] == name [j])
                {
                    
                }
            }
        }
    }
    else
    {
        cout << "Failed to open attendance files" << endl;
    }
    file.close();





}

