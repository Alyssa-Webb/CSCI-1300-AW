// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 8

#include <iostream> 
#include <string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std; 

struct Candy
{
    string name;
    string description;
    double price;
    string candy_type;
};

class Player 
{
    private:
        const static int _MAX_CANDY_AMOUNT = 4;  // maximum number of candies the player can have in their inventory. (Use the value of 4 for this homework)
        
        int _stamina;                        // current energy
        double _gold;                        // value of the player's current money
        string _effect;                      // name of current effect
        Candy _inventory[_MAX_CANDY_AMOUNT]; // array to store the player's candy
        int _candy_amount;                   // amount of initialized candy structs in the inventory array

    public:
        /* DEFAULT CONSTRUCTORS */
        Player();
        Player(int stamina, double gold, string effect, Candy[], const int CANDY_ARR_SIZE);

        /* GETTERS */
        int getCandyAmount() const;        // returns the amount of candy the player has in their inventory
        int getStamina() const;            // returns the current value of stamina as an integer
        double getGold() const;            // returns the current value of gold as a double
        string getEffect() const;          // returns the current value of effect as a string

        /* SETTERS */
        void setStamina(int stamina);	    // takes an integer as input, and sets stamina to the input value.
        void setGold(double gold);	    // takes a double as input, and sets gold to the input value.
        void setEffect(string effect);	// takes a string as input, and sets effect to the input value.

        /* OTHER FUNCTIONS*/
        void printInventory();	                    // Prints out the player's current inventory.
        Candy findCandy(string candy_name);         // Searches for a Candy in the Player's inventory.  
        bool addCandy(Candy candy);	                        // Adds a Candy to the Player's inventory.
        bool removeCandy(string candy_name);	                    // Removes a Candy from the Player's inventory. 
        void playRockPaperScissors(Player players[2]);          // Takes Player1 & Player2 bets(candy from inventory) and hands(R,P,S), determines winner, allocating winner/loser bets
}; 

