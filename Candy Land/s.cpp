//#include "Player.cpp"
#include "6_Player.h"
#include <iostream> 
using namespace std; 

//Rock Paper Scissors
void playRockPaperScissors(Player players[2])
{
    string player1Candy; 
    string player2Candy; 
    char player1select; 
    char player2select;  
    string player1CandyLower;
    string player2CandyLower;
    Candy player1stu = players[0].findCandy(player1CandyLower);
    Candy player2stu = players[1].findCandy(player2CandyLower);
    bool bet1Found = false;
    bool bet2Found = false; 

    
    // input: Player 1 and 2 candy -> check inventory to see if they have candy -> if they don't say not enough candy - if they do check if they have the candy selection in their inventory
    
    
    /*for(int i= 1; i < int(player2Candy.length()); i++)
    {
        tolower(player2Candy[i]); 
    }*/

   

    if (players[0].getCandyAmount() == 0 || players[1].getCandyAmount() == 0)
    {
            cout << "Not enough candy!" << endl;
            return;
    }
    else 
    {
        cout << "Player 1 Inventory" << endl;
        players[0].printInventory();
        cout << "Player 1: Select candy to bet" << endl; 
        //cin >> player1Candy; 
        getline(cin, player1Candy);
        int len1 = player1Candy.length();
        for (int i = 0; i < len1; i++)
        {
            player1CandyLower += tolower(player1Candy[i]); 
        }
        while(bet1Found == false)
        {

            player1stu = players[0].findCandy(player1CandyLower);
            // cout << "player1stu " << player1stu.name;
            if(player1stu.name == "")
            {
                cout << "Invalid selection!" << endl;
                getline(cin, player1Candy);
                player1CandyLower = "";
                for (int i = 0; i < player1Candy.length(); i++)
                {
                    player1CandyLower += tolower(player1Candy[i]); 
            
                }
            }
            else
            {
                bet1Found = true;
            }

        }
        
       


        cout << "Player 2 Inventory" << endl;
        players[1].printInventory();
        cout << "Player 2: Select candy to bet" << endl; 
        //cin >> player2Candy; 
        getline(cin, player2Candy);
        int len2 = player2Candy.length();
        // cout <<" player2CandyLower before  " << player2CandyLower;

        for (int i = 0; i < len2; i++)
        {
            player2CandyLower += tolower(player2Candy[i]); 
            
        }
        //cout <<" player2CandyLower after " << player2CandyLower;
        while(bet2Found == false)
        {
            player2stu = players[1].findCandy(player2CandyLower);
            if(player2stu.name == "")
            {
                cout << "Invalid selection!" << endl;
                getline(cin, player2Candy);
                player2CandyLower = "";
                for (int i = 0; i < player2Candy.length(); i++)
                {
                    player2CandyLower += tolower(player2Candy[i]); 
                
                }
            }
            else
            {
                bet2Found = true;
            }

        }
    }
  



// input player 1 and 2 r p s 
bool playAgain = true; 


while(playAgain == true)
{
    cout << "Player 1: Enter r, p, or s" << endl; 
    cin >> player1select; 
    while(cin.fail() || (player1select != 'r' && player1select != 'p' && player1select != 's'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid selection!" << endl;
        cin >> player1select;
    }

    cout << "Player 2: Enter r, p, or s" << endl; 
    cin >> player2select; 
    while(cin.fail() || (player2select != 'r' && player2select != 'p' && player2select != 's'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid selection!" << endl;
        cin >> player2select;
    }


    switch (player1select)
    {
        case 'r':
            if(player2select == 'r')
            {
                // tie 
                cout << "Tie! Play again" << endl; 

            }

            if(player2select == 'p')
            {
                // player 2 wins 
                players[1].addCandy(player1stu); 
                players[0].removeCandy(player1stu.name);
                cout << "Player 2 has won " << player1Candy << " from player 1!" << endl;
                playAgain = false; 
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory();*/

            
            }

            if(player2select == 's')
            {
                //player 1 wins
                players[0].addCandy(player2stu); 
                players[1].removeCandy(player2stu.name);
                cout << "Player 1 has won " << player2Candy << " from player 2!" << endl;
                playAgain = false; 
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory();*/
            
            }

            break;

        case 'p':
            if(player2select == 'r')
            {
                // player 1 wins 
                players[0].addCandy(player2stu); 
                players[1].removeCandy(player2stu.name);
                cout << "Player 1 has won " << player2Candy << " from player 2!" << endl;
                playAgain = false; 
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory(); */
               


            }
            if(player2select == 'p')
            {
                //tie
                cout << "Tie! Play again" << endl; 

            }
            if(player2select == 's')
            {
                //player 2 wins 
                players[1].addCandy(player1stu); 
                players[0].removeCandy(player1stu.name);
                cout << "Player 2 has won " << player1Candy << " from player 1!" << endl;
                playAgain = false; 
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory();*/
               

            }
        
            break;

        case 's':
            if(player2select == 'r')
            {
                //player 2 wins 
                players[1].addCandy(player1stu); 
                players[0].removeCandy(player1stu.name);
                cout << "Player 2 has won " << player1Candy << " from player 1!" << endl;
                playAgain = false; 
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory();*/
                

            }
            if(player2select == 'p')
            {
                // player 1 wins
                players[0].addCandy(player2stu); 
                players[1].removeCandy(player2stu.name);
                cout << "Player 1 has won " << player2Candy << " from player 2!" << endl;
                playAgain = false;  
                /*cout << "Player 1 Inventory after: " << endl; 
                players[0].printInventory();
                cout << "Player 2 Inventory after: " << endl; 
                players[1].printInventory();*/
                 

            }
            if(player2select == 's')
            {
                // tie
                cout << "Tie! Play again" << endl; 

            }
        
            break;
        
        }

        
    }   
   
} // param: array with two class objects 

// input player 1 and 2 r p s 

// switch statement? for each input value for player 1 -> if statements for each  input statement of player 2 
// rr, rp , rs, pp, pr, ps, ss, sr, sp
// cout the selected candy based on which player won 
