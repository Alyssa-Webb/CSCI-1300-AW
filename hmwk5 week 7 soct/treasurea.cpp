    // CSCI 1300 Fall 2023
    // Author: Alyssa Webb
    // TA: Anil
    // Question 5a

    #include<iostream>
    #include<iomanip>
    #include<cmath>

    using namespace std; 

    void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int CLUE_ROWS, const int CLUE_COLS, const int REG_ROWS, const int REG_COLS); 
    // distance formula: distance (p1,p2) = sqrt((x^2-x^1)^2 + ((y^2-y^1)^2)))

    int main()
    {
        // clues
        int clue_rows = 5; 
        int clue_cols = 2; 
        // regular
        int reg_rows = 3;  
        int reg_cols = 2; 

        // define the distance matrix 
        const int clue_rows = 5;
        // cords of 5 clues
        double clue[clue_rows][clue_cols] = {{2, 10}, 
                                            {2, 5},
                                            {8, 4}, 
                                            {5, 8}, 
                                            {1, 2}};

        // regions of the island
        double region[reg_rows][reg_cols] = {{2, 10}, 
                                            {5, 8}, 
                                            {1, 2}};
        
        return 0; 
    }

    // void doesnt return
    void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], const int clue_rows, const int clue_cols, const int reg_rows, const int reg_cols) 
    {
        for (int i = 0; i < clue_rows; i++) // iterates through clues
        {
            for (int j = 0; j < reg_rows; j++) // iterates through what we have
            {
                double clue1 = clue[i][0] - region[j][0]; // subtracting x-values (x2 - x1)
                double clue2 = clue[i][1] - region[j][1]; // finding difference in y coords (y2 - y1)
                
                distance[i][j] = sqrt((pow(clue1, 2))+(pow(clue2, 2))); // squared it down here
            }
        }
    }
