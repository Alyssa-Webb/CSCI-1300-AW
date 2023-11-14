#include "PlayerClass.h"

// DEFAULT PLAYER
Player::Player()
{
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _effect = " ";
    
    Candy empty_candy = {"", "", 0.0, ""};
    for (int i = 0; i < _MAX_CANDY_AMOUNT; ++i) 
    {
        _inventory[i] = empty_candy;
    }
    
}

// DEFAULT PLAYER w/ PARAMETERS
Player::Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE)
{
    Candy empty_candy = {"Empty", "", 0.0, ""}; 
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    _candy_amount = 0;
    
    for (int i = 0; i < CANDY_ARR_SIZE; i++)
    {
        if (candy_array[i].name.length() == 0) 
        {
            _inventory[i] = empty_candy; 
        }
        else if (_candy_amount < _MAX_CANDY_AMOUNT)
        {
            _inventory[i] = candy_array[i];
            _candy_amount++;
        }
    }
}


// returns the amount of candy the player has in their inventory
int Player::getCandyAmount() const
{
    return _candy_amount;
}

// returns the current value of stamina as an integer
int Player::getStamina() const
{
    return _stamina;
}

// returns the current value of gold as a double
double Player::getGold() const
{
    return _gold;
}

// returns the current value of effect as a string
string Player::getEffect() const
{
    return _effect;
}

void Player::setStamina(int stamina)	    // takes an integer as input, and sets stamina to the input value.
{
    _stamina = stamina;
}

void Player::setGold(double gold)	    // takes a double as input, and sets gold to the input value.
{
    _gold = gold;
}
void Player::setEffect(string effect)	// takes a string as input, and sets effect to the input value.
{
    _effect = effect;
}

/* FORMAT*/
// |[Empty]|[Empty]|
// |[Empty]|[Empty]|
void Player::printInventory()
{
    for(int i= 0; i < _MAX_CANDY_AMOUNT; i++)   // prints candy until max (4)
    {
        
        if(i == 1 || i == 3)    // if in second column ( 1 & 3 )
        {
            if(_inventory[i].name == "")
            {
            cout << "[Empty]|" << endl; 
            }
            else 
            {
                cout << "[" << _inventory[i].name <<  "]|"  // prints candy
                << endl; // new line since last in row

            }
        }
        else                    // if in first column ( 0 & 2 )
        {
            if(_inventory[i].name == "")
            {
                cout << "|[Empty]|"; 
            }
            else 
            {
                cout << "|[" << _inventory[i].name  << "]|"; // prints candy

            }  
        }
    }
}

/*void Player::printInventory() const // prints out the player's current inventory using 2x2
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++)
        {
            if (_inventory[i].name.empty())
            {
                cout << "|[Empty]";
            }
            else
            {
                cout << "|[" << _inventory[i].name << "]";
            }
        }
        cout << "|";
        cout << endl;
    }
}
*/

Candy Player::findCandy(string candy_name) // finds a specified candy in player inventory
{
    string candy_name_lower = ""; // will be used to be case insensitive

    for (int i = 0; i < candy_name.length(); ++i) // converts every letter to lowercase
    {
        candy_name_lower += tolower(candy_name[i]);
    }

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        string current_candy = _inventory[i].name; // stores name of current candy at index
        string current_candy_lower = ""; // store lowercase "current_candy"


        for (int j = 0; j < current_candy.length(); j++)
        {
            current_candy_lower += tolower(current_candy[j]);
        }

        if (current_candy_lower == candy_name_lower)
        {
            return _inventory[i]; // found, return the first candy with specified name
        }
    }

    return Candy{"", "", 0.0, ""};     // return an "empty" Candy if not found
}


bool Player::addCandy(const Candy candy)    
{
    if (candy.name.length() == 0)   // checks if candy input was empty
    {
        return false;
    }
    if (_candy_amount < _MAX_CANDY_AMOUNT)
    {
        _inventory[_candy_amount++] = candy; // candy added if inventory not full
        return true;
    }
    else
    {
        return false; // if the inventory is full, return false
    }
}

bool Player::removeCandy(string candy_name)     // removes a Candy from the Player's inventory 
{
    int len = candy_name.length();            // length of the candy's name
    string lower_candy_name = "";             // initialize as an empty string

    for (int i = 0; i < len; i++)             // iterate over each character
    {
        lower_candy_name += tolower(candy_name[i]); // convert entire string to lower case
    } 
    
    for (int i = 0; i < _MAX_CANDY_AMOUNT - 1; i++) // iterate up to the second last element
    {
        string lower_inv_name = "";                   // initialize as an empty string
        for (int j = 0; j < _inventory[i].name.length(); j++) // iterate over each character
        {
            lower_inv_name += tolower(_inventory[i].name[j]); // convert entire string to lower case
        } 

        if (lower_inv_name == lower_candy_name) // sees if current index matches candy
        {
            _candy_amount--; // update candy amount
            
            // shift the elements to fill the gap caused by removing the candy
            for (int k = i; k < _MAX_CANDY_AMOUNT - 1; k++) // k is set to i since i is where the index was found
            {
                _inventory[k] = _inventory[k + 1];          // removes the candy, and increases inventory to remove gap (3 instead of 4 slots)
            }
            
            return true;    // successfully removed
        }
    }
    return false; // candy not found, returns false
}


/*bool Player::removeCandy(string candy_name)	    // removes a Candy from the Player's inventory 
{   
    int len = candy_name.length();            // length of the candy's name
    string lower_candy_name = candy_name;    // sought for candy              
    
    for (int i = 0; i < len; i++)           // for as long as the string is
    {
        lower_candy_name += tolower(candy_name[i]); // converts entire string to lower case
    } 
    
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)     // continues based on inventory
    {
        string lower_inv_name = _inventory[i].name; // current candy index in inventory

        for (int j = 0; j < len; j++)
        {
            lower_inv_name += tolower(_inventory[i].name[j]); // converts entire string to lower case
        } 

        if (lower_inv_name == lower_candy_name) // sees if current index matches candy
        {
            _candy_amount--; // update candy amount
            _inventory[i] = _inventory[i + 1];
            return true;    // successfully removed
        }
    }
    return false; // candy not found, returns false
}*/


