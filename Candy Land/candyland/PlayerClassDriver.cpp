#include "PlayerClass.h"
#include "PlayerClass.cpp"

vector<Candy> readCandy(string file_name, vector<Candy> candies); // prototype - reads candies & candy info from file and store in vector
void playRockPaperScissors(Player players[2]); // prototype - allows two players to play rock paper scissors

int main ()
{
    // pre-loaded information
    // player 1, player 2, files
    vector<Candy> loaded_candies; // from file
    Player player1 = Player();
    Player player2 = Player();  
    Player players[2] = {player1, player2};

    // navigating menu
    int menu_input;
    string file_name; // file from user that provides "loaded_candies"
    string candy_choice_d; // player chooses which candy they would like to add
    string remove_candy_d; // the candy the player wants to remove
    bool candy_removed_d; // determines if the candy was correctly removed from inventory
    
    //edit stats
    int player_stats_d; // placeholder for stats
    int edit_player_stats_d; // the choice of which player's stats to edit
    int stat_choice_d; // player choice of what stat to edit
    int edit_stamina_d; // player chooses how to edit their stam
    double edit_gold_d; // player chooses how to edit their gold
    string edit_effect_d; // player chooses what effect to edit
    Candy add_candy_d; // adds designated candy & info to player inventory
    
////////////* WELCOME SCREEN */////////////////////////////////////////////////////////////////////////
    cout << "Welcome to rock-paper-scissors, candy edition!" << endl;       // welcome screen *starts*
    
    do  // while user doesnt pick 5, to exit program
    {
    /* DISPLAY OPTIONS */ 
        cout << "Choose an option:" << endl; 
        cout << "1. Load Candy" << endl; 
        cout << "2. Display player stats " <<  endl; 
        cout << "3. Edit player stats " << endl; 
        cout << "4. Play rock-paper-scissors" << endl; 
        cout << "5. Exit" << endl; 

    // menu input -- need to validate input
        cin >> menu_input; 
        cin.ignore();

        while(cin.fail() || menu_input < 1 || menu_input > 5) // validates user input, loops until valid
        {   
            cout << "Invalid input" << endl;
            cin.clear(); // clears input buffer
            cin.ignore(1000, '\n'); // ignores next [arbitray number] to avoid unnecessary chars
            // takes input again until valid
            cin >> menu_input;
        }

    // based on user input, the following:
    switch (menu_input)
    {
        case 1: // Load Candy -- from file
            cout << "Enter file to read:" << endl; // asks for user to input file
            cin >> file_name;                      // stores file from user
            loaded_candies = readCandy(file_name, loaded_candies);  //
        break;

        case 2: // Display player stats -- Player 1 or Player 2, check input
            cout << "Which player's stats do you want to display? Choose 1 or 2:" << endl;
                    cin >> player_stats_d;
                    cin.ignore(); // ignores buffer

                    while(cin.fail() || player_stats_d < 1 || player_stats_d > 2) // validates user input, loops until valid
                    {   
                        cout << "Invalid input" << endl;
                        cin.clear(); 
                        cin.ignore(10000, '\n'); 
                        cin >> player_stats_d;
                    }
            /* PLAYER 1 STATS */
            switch (player_stats_d)
            {
                case 1:
                    cout << "Player 1 stats:" << endl; 
                    cout << "Stamina: " << players[0].getStamina() << endl; 
                    cout << fixed << setprecision(2) << "Gold: " << players[0].getGold() << endl; 
                    cout << "Effect: " << players[0].getEffect() << endl; 
                    cout << "Inventory: " << endl; 
                    players[0].printInventory();
                    break;
                case 2:
                    cout << "Player 2 stats:" << endl; 
                    cout << "Stamina: " << players[1].getStamina() << endl; 
                    cout << fixed << setprecision(2) << "Gold: " << players[1].getGold() << endl; 
                    cout << "Effect: " << players[1].getEffect() << endl; 
                    cout << "Inventory: " << endl; 
                    players[1].printInventory();
            }
        break; 

        case 3: // Edit player stats
        cout << "Which player's stats do you want to edit? Choose 1 or 2:" << endl;
            cin >> edit_player_stats_d;
            cin.ignore();
            while(cin.fail() || edit_player_stats_d < 1 || edit_player_stats_d > 2) // validates user input, loops until valid
            {   
                cout << "Invalid input" << endl;   
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cin >> edit_player_stats_d;
            }
        /* DISPLAY EDIT STATS MENU */
            cout << "Editing player " << edit_player_stats_d << " stats:" << endl; // player [1] or [2]
            cout << "1. Edit stamina" << endl;
            cout << "2. Edit gold" << endl;
            cout << "3. Edit effect" << endl;
            cout << "4. Add candy" << endl;
            cout << "5. Remove candy" << endl;
                
            cin >> stat_choice_d; // STAT INPUT & VERIFYING INPUT  
            cin.ignore();
            
            while(cin.fail() || stat_choice_d < 1 || stat_choice_d > 5) // // validates user input, loops until valid
            {   
                cout << "Invalid input" << endl;
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cin >> stat_choice_d;
            }

            switch (stat_choice_d)   
            {
                case 1: // edit stamina (1-10)
                    cout << "Editing stamina. Enter a value between 1 and 10:" << endl; // display function processing
                    cin >> edit_stamina_d;

                    while(cin.fail() || edit_stamina_d < 1 || edit_stamina_d > 10) // validates user input, loops until valid
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input!" << endl;
                        cin >> edit_stamina_d;
                    }

                    players[edit_player_stats_d - 1].setStamina(edit_stamina_d); // -1 since user choice starts with 1, not 0
                break; 
                case 2: // edit gold (1-1000)
                    cout << "Editing gold. Enter a value between 0 and 1000:" << endl; //display function processing
                    cin >> edit_gold_d;

                    while(cin.fail() || edit_gold_d < 0 || edit_gold_d > 1000) // validates user input, loops until valid
                    { 
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input!" << endl;
                        cin >> edit_gold_d;
                    }

                    players[edit_player_stats_d - 1].setGold(edit_gold_d); // -1 since user choice starts with 1, not 0

                break; 
                case 3: // edit effect (any string) -- getline since its a string w/ spaces
                    cout << "Editing effect. Enter the name of an effect as a string:" << endl;
                    getline(cin, edit_effect_d);
                    players[edit_player_stats_d - 1].setEffect(edit_effect_d); // -1 since user choice starts with 1, not 0
                break;
                case 4: // add candy, display a list of possible candies to add to the inventory
                // must first check if a file has been read to display said candies
                    if (loaded_candies.size() == 0) // vector of candies is empty
                    {
                        cout << "Cannot add candy! Read a candy file first" << endl;
                        break; // will leave these cases and take user back to main menu
                    } 
                    else if (loaded_candies.size() > 0)
                    {
                        cout << "Adding candy. Enter one of the following options:" << endl;

                        for(int i = 0; i < loaded_candies.size(); i++) // will iterate through the vector of candies loaded from the candies file
                        {
                            cout << fixed << setprecision(2)                        // 0.00 format for gold
                            << "Name: " << loaded_candies[i].name                   // name of candy
                            << ". Description: " << loaded_candies[i].description   // candy description
                            << ". Price: " << loaded_candies[i].price               // price of candy
                            << ". Type: " << loaded_candies[i].candy_type           // type of candy
                            << endl;
                        }
                        getline(cin, candy_choice_d); // will take user input on which candy they would like to add
                        
                        string candy_choice_lower = ""; // lowercase of user input for comparison
                        for (int j = 0; j < candy_choice_d.length(); j++)
                        {
                            candy_choice_lower += tolower(candy_choice_d[j]);
                        }   

                        while(candy_choice_lower != "fearsome fudge" && candy_choice_lower != "tricky treacle" && candy_choice_lower != "lucky licorice" && candy_choice_lower != "strengthening skittles")
                        {
                            cout << "Invalid input!" << endl;   // if candy is not what is in the file, it is invalid
                            getline(cin, candy_choice_d); // input taken again
                            candy_choice_lower = ""; // clear original input
                            for (int j = 0; j < candy_choice_d.length(); j++) // set to lowercase for another comparison
                            {
                                candy_choice_lower += tolower(candy_choice_d[j]); 
                            }  
                        }

                        if(candy_choice_lower == "fearsome fudge") // FEARSOME FUDGE
                        {
                            add_candy_d = {"Fearsome Fudge", "A delectably dangerous confectionary concoction! Causes fright!", 4.37, "Debuff"};
                            players[edit_player_stats_d - 1].addCandy(add_candy_d); // adds Fearsome Fudge and info to the player inventory
                        } 
                        else if(candy_choice_lower == "tricky treacle") // TRICKY TREACLE
                        {
                            add_candy_d = {"Tricky Treacle", "Some deliciously tart treacle. Warning, may cause bad luck!", 2.79, "Debuff"};
                            players[edit_player_stats_d - 1].addCandy(add_candy_d); // adds Tricky Treacle and info to the player inventory
                        } 
                        else if(candy_choice_lower == "lucky licorice") // LUCKY LICORICE
                        {
                            add_candy_d = {"Lucky Licorice", "A subtly sweet licorice, known to bring good luck to the owner", 3.15, "Buff"};
                            players[edit_player_stats_d - 1].addCandy(add_candy_d); // adds Lucky Licorice and info to the player inventory
                        } 
                        else // STRENGTHENING SKITTLES
                        {
                            add_candy_d = {"Strengthening Skittles", "A valuable pack of skittles reknowned for their ability to provide super-human strength", 7.77, "Buff"};
                            players[edit_player_stats_d - 1].addCandy(add_candy_d); // adds Strengthening Skittles and info to the player inventory
                        }
                    }
                break;
                case 5: // remove candy -- boolean used because remove candy returns T/F on whether it was removed

                    cout << "Removing candy. Enter the name of a candy in player " << edit_player_stats_d << "'s inventory:" << endl;
                    candy_removed_d = false;  // candy has yet to be removed, default set to false
                    players[edit_player_stats_d - 1].printInventory();

                    do // while the candy has not been removed, continue 
                    {
                        getline(cin, remove_candy_d); // takes input of which candy to remove 
                        candy_removed_d = players[edit_player_stats_d - 1].removeCandy(remove_candy_d); // using the array for player [0] or [1] (1,2),
                                                                                                  // remove candy function returns if the candy can be removed
                        if (!candy_removed_d) {
                            cout << "Invalid input! Try again." << endl; // invalid input, candy cannot be removed (i.e. DNE)
                        }

                    } while (!candy_removed_d); // when candy is removed, loop will exit
                break;
            }
        break;
        case 4: // Play rock-paper-scissors -- players (Player 1 & Player 2) -- need function prototype
            playRockPaperScissors(players);
        
        break; 
        case 5: // Exit program -- nothing displayed?
        // no goodbye
        break;
    }



    } while (menu_input != 5);
    return 0; // program ends if loop is complete
}

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
            getline(ss, new_candy.name, '|'); // string stream, adding the new candy name to the structure, then the delimiiter
            if(new_candy.name == "")
            {
                continue; // program will skip remainder of the loop, and continue after ""
            }
            
            getline(ss, new_candy.description,'|'); // string stream,  corresponding candy desc to name, delimiter
            getline(ss, price,'|');  // string stream,  corresponding candy price to name, desc, delimiter
            cout << setprecision(2) << fixed;   // 0.00
            new_candy.price = stod(price); // string to int
            getline(ss,new_candy.candy_type); 

            candies.push_back(new_candy); // puts new candy in vector
        } 

    }
    candy_file.close(); // closes file after being read
    return candies; // returns the vector of candies that were read from file
}