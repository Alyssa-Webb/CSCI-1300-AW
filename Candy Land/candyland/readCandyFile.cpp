#include "PlayerClassDriver.cpp"

/* READ CANDIES FILE */
vector<Candy> readCandy(string file_name, vector<Candy> candies) // purpose is to read candies from file and add to a candies vector for loaded candies
{                                                                // necessary to play game
    Candy new_candy;    // candy being added to vector
    string line, price; // for stringstream

    ifstream candy_file(file_name); // open candies file
    
    if(!candy_file.is_open())  // if file failed to open
    {
        cout << "Failed to open file" << endl; 
        return candies;
    }
    else
    {
   
        while(getline(candy_file, line)) 
        {
            stringstream ss(line);
            getline(ss,new_candy.name, '|');
            if(new_candy.name == "")
            {
                continue; // program will skip remainder of the loop, and continue after ""
            }
            
            getline(ss, new_candy.description,'|'); 
            getline(ss, price,'|'); 
            cout << setprecision(2) << fixed;   // 0.00
            new_candy.price = stod(price); // string to int
            getline(ss,new_candy.candy_type); 

            candies.push_back(new_candy); // puts new candy in vector
        } 

    }
    candy_file.close(); // closes file after complete
    return candies; // returns the vector of candies from file
}