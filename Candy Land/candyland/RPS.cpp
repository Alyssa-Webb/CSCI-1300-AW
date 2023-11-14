#include "PlayerClass.cpp"
#include "PlayerClass.h"

/* ROCK PAPER SCISSORS */

void playRockPaperScissors(Player players[2]) // Takes Player1 & Player2 bets(candy from inventory) and hands(R,P,S), determines winner, allocating winner/loser bets
{
    bool winner = false;    // loop continues until there is a winner
    bool bet1 = false;      // determines if player 1 bet is valid
    bool bet2 = false;      // determines if player 2 bet is valid

    string player1_candy, player2_candy = " "; // will hold the candy that will be bet
    string player1_candy_lower, player2_candy_lower; // lowercase candy bet
    char player1_input, player2_input = ' ';    // rock paper or scissor input
    Candy player1_can = players[0].findCandy(player1_candy_lower);      // finds player 1 candy based on lowercase input
    Candy player2_can = players[1].findCandy(player2_candy_lower);      // finds player 2 candy based on lowercase input

    if (players[0].getCandyAmount() == 0  || players[1].getCandyAmount() == 0) // if either inventory is empty, cannot continue
    {
        cout << "Not enough candy!" << endl;
        winner = true; // no candy, no winner, no game
    }
    else if (players[0].getCandyAmount() > 0  && players[0].getCandyAmount() > 0) // if they have candy, game continues
    {
        /* PLAYER 1 */
        cout << "Player 1 Inventory" << endl;
        players[0].printInventory();

        cout << "Player 1: Select candy to bet" << endl;

        // Accepting input (allowing spaces with getline)
        getline(cin, player1_candy);

        // Validate the candy selection
        while (bet1 == false)   // Player 1 has to make valid selection
        {
            string player1_candy_lower;         // convert to lowercase for comparison (case insensitive)
            for (int i = 0; i < player1_candy.length(); i++)
            {
                player1_candy_lower += tolower(player1_candy[i]);
            }

            player1_can = players[0].findCandy(player1_candy_lower);

            if (player1_can.name == "") // if candy does not exist in inventory
            {
                cout << "Invalid selection!" << endl;             // accepting input again

                getline(cin, player1_candy);
            }
            else
            {
                bet1 = true; // valid selection, exit the loop
            }
        }
        /* PLAYER 2 */
        cout << "Player 2 Inventory" << endl;
        players[1].printInventory();

        cout << "Player 2: Select candy to bet" << endl;

        // Accepting input (allowing spaces with getline)
        getline(cin, player2_candy);

        // Validate the candy selection
        while (bet2 == false)   // Player 2 has to make valid selection
        {
            string player2_candy_lower;         // convert to lowercase for comparison (case insensitive)
            for (int i = 0; i < player2_candy.length(); i++)
            {
                player2_candy_lower += tolower(player2_candy[i]);
            }

            player2_can = players[1].findCandy(player2_candy_lower);

            if (player2_can.name == "") // if candy does not exist in inventory
            {
                cout << "Invalid selection!" << endl;             // accepting input again

                getline(cin, player2_candy);
            }
            else
            {
                bet2 = true; // valid selection, exit the loop
            }
        }
    }
    /* ROCK PAPER SCISSORS STARTS*/
    while (!winner)         // game only continues if both players have bet and there's no winner
     {
        // player 1
        cout << "Player 1: Enter r, p, or s" << endl;
        cin >> player1_input;
            while(cin.fail() || (player1_input != 'r' && player1_input != 'p' && player1_input != 's'))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid selection!" << endl;
                cin >> player1_input;
            }

        // player 2        
        cout << "Player 2: Enter r, p, or s" << endl;
        cin >> player2_input;
            while(cin.fail() || (player2_input != 'r' && player2_input != 'p' && player2_input != 's'))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid selection!" << endl;
                cin >> player2_input;
            }
        

        switch (player1_input)          // based on Player 1 input 
        {
            case 'r': // PLAYER 1 CHOOSES ROCK
                if (player2_input == 'r')       // PLAYER 2 CHOOSES ROCK
                {
                    cout << "Tie! Play again" << endl;
                    winner = false;
                    break;
                }
                else if (player2_input == 'p')  // PLAYER 2 CHOOSES PAPER
                {
                    // Player 2 wins
                    cout << "Player 2 has won " << player1_candy << " from player 1!" << endl;
                    players[1].addCandy(player1_can); 
                    players[0].removeCandy(player1_can.name);
                    winner = true;
                }
                else if (player2_input == 's')  // PLAYER 3 CHOOSES SCISSORS
                {
                    // Player 1 wins
                    cout << "Player 1 has won " << player2_candy << " from player 2!" << endl;
                    players[0].addCandy(player2_can); // adds player 2 candy to player 1
                    players[1].removeCandy(player2_can.name);
                    winner = true;
                }
                else 
                {
                    cout << "Invalid selection!" << endl;
                    break;
                }
            break;
            
            case 'p': // PLAYER 1 CHOOSES PAPER
                if (player2_input == 'r')
                {
                    // Player 1 wins
                    cout << "Player 1 has won " << player2_candy << " from player 2!" << endl;
                    players[0].addCandy(player2_can); // adds player 2 candy to player 1
                    players[1].removeCandy(player2_can.name);
                    winner = true;
                }
                else if (player2_input == 'p')
                {
                    cout << "Tie! Play again" << endl;
                    winner = false;
                    break;
                }
                else if (player2_input == 's')
                {
                    // Player 2 wins
                    cout << "Player 2 has won " << player1_candy << " from player 1!" << endl;
                    players[1].addCandy(player1_can); 
                    players[0].removeCandy(player1_can.name);
                    winner = true;
                }
                else 
                {
                    cout << "Invalid selection!" << endl;
                    break;
                }
            break;
            
            case 's': // PLAYER 1 CHOOSES SCISSORS
                if (player2_input == 'r')
                {
                    // Player 2 wins
                    cout << "Player 2 has won " << player1_candy << " from player 1!" << endl;
                    players[1].addCandy(player1_can); 
                    players[0].removeCandy(player1_can.name);
                    winner = true;
                }
                else if (player2_input == 'p')
                {
                    // Player 1 wins
                    cout << "Player 1 has won " << player2_candy << " from player 2!" << endl;
                    players[0].addCandy(player2_can); // adds player 2 candy to player 1
                    players[1].removeCandy(player2_can.name);
                    winner = true;
                }
                else if (player2_input == 's')
                {
                    cout << "Tie! Play again" << endl;
                    winner = false;
                    break;
                }
                else 
                {
                    cout << "Invalid selection!" << endl;
                    break;
                }
            break;
            
            default:
                cout << "Invalid selection!" << endl;
        }
            if (winner) // prevent an infinite loop
            {
                break;
            }
    }
        //cout << "Player 1 Inventory After:" << endl;
        //players[0].printInventory();
        //cout << "Player 2 Inventory After:" << endl;
        //players[1].printInventory();
}