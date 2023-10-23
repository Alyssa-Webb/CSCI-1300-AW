// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 5b
#include<cmath>
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


// x = rows
// y = columns

// void doesnt return

    void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int clue_rows, const int clue_cols, const int reg_rows, const int reg_cols) 
    {
        for (int x = 0; x < clue_rows; x++) // iterates through clues
        {
            for (int y = 0; y < reg_rows; y++) // iterates through what we have
            {
                double clue1 = clue[x][0] - region[y][0]; // subtracting x-values (x2 - x1)
                double clue2 = clue[x][1] - region[y][1]; // finding difference in y coords (y2 - y1)
                
                distance[x][y] = sqrt((pow(clue1, 2))+(pow(clue2, 2))); // squared it down here
            }
        }
    }

    void findClueRegion(double distance[][3], int clue_regions[], const int distance_rows, const int distance_cols)
    {
        double min_distance = 0;

        // go through rows in distance matrix
        for(int x = 0; x < distance_rows; x++) // iterates row values
        {
            min_distance = distance[x][0]; // iterating through x values, y value determined by j, so y = 0
            int temp = 0; // resets value of temp each iteration
            
            for (int y = 0; y < distance_cols; y++)  // interates the column values
            {
                // find minimum value based on rows and cols now 
                if(distance[x][y] < min_distance) // less than the min value that was already set 
                {
                    min_distance = distance[x][y]; // make this the min value now and store that into the temp 
                    temp = y;
                }
            }
        
        if(temp == 0)
        {
            clue_regions[x] = temp + 1; // for region 1
        } 
        else if (temp == 1)
        {
            clue_regions[x] = temp + 1; // for region 2
        } 
        else if(temp == 2)
        {
            clue_regions[x] = temp + 1; // for region 3
        }    

    }
    }
        

void findTreasure(int clue_regions[], double region[][2], const int clue_regions_size, const int reg_rows, const int reg_cols)
{
    int index_1 = 0;
    int index_2 = 0;
    int index_3 = 0;
    
    int region_number = 0;
    
    int index[3] = {}; // regions array 

    // iterates through each of the regions when i = (1, 2, 3)
    // to count the number of clues
    for(int i = 0; i < clue_regions_size; i++) {
     
        if(clue_regions[i] == 1) {
            index_1++; // if the clue is in region one add to an index to count the values up 
         
        }
        if(clue_regions[i] == 2) {
            index_2++;
         
        }
        if(clue_regions[i] == 3) {
            index_3++;

        } 
    }
    
    index[0] = index_1; // set the array number equal to the index in each region to count up the number of clues in each one 
    index[1] = index_2;
    index[2] = index_3;
    
    // treasure is buried in the region with the least amount of clues
    int min_distance = 321;
    for(int i = 0; i < 3; i++)
    {
        if(index[i] < min_distance)
        {
            min_distance = index[i]; // set the min value 
            region_number = i + 1; // add 1 to match column number over index value
        }
    }
    
    cout << "Region " << region_number << " had the least number of clues : " << min_distance << endl;
    
    double x = region[region_number - 1][0]; // back to index value
    double y = region[region_number -1][1]; // back to index value
   
    cout << "Treasure must be buried in the coordinates ( " << fixed << setprecision(2) << x << ", " << fixed << setprecision(2) << y << " )" << endl;
    
}