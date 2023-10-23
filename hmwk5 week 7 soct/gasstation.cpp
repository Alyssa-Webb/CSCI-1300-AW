// CSCI 1300 Fall 2023
// Author: Alyssa Webb
// TA: Anil
// Question 4

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std; 

vector<string> addProduct(vector <string> cart, char product, double budget);
vector<string> removeProduct(vector<string> cart, string productR, double budget);

double beforeTax (vector<string> cart);
double addSum(vector<string> cart);
void checkout (vector<string> cart);

int main ()
{
    //input
    double budget = 0;
    double new_budget;
    double current_budget = 0;
    int user_input = 0;
    char product;
    string productR;
    string remove_product = "";

    // vector cart
    vector<string> cart;

    // menu cost
    const double cheetos = 2.99; 
    const double oreos = 3.39;
    const double coffee = 3.79;
    const double slurpee = 4.29;

    // welcome screen
    // ask user for budget
    cout << "Welcome to Kroga Gas Station!\n"
        << "Enter your budget:\n";
    cin >> budget;
    
    // if user input is invalid  
    if (budget <= 0)
    {
        cout << "Invalid input. Balance must be a non-negative value." << endl;
        return 1; // terminates program
    }
    new_budget = budget;
do // do while to loop to continuously show menu until conditions met
{
    cout << "Please input 1-4 followed by enter to navigate the menu:\n" 
            << "1) Add Product\n"
            << "2) Remove Product\n"
            << "3) Checkout\n"
            << "4) Exit"
            << endl;
    
    cin >> user_input; 
    // if user input is invalid  
    while (cin.fail() || user_input < 1 || user_input > 4) 
        // cin.fail becomes true when user_input is invalid, evaluates true
        // if user input is 0 or negative, invalid, evaluates true
        // if user input is beyond program limits (6), invalid, evaluates true
    { 
        cout << "Invalid input." << endl;    // outputs to the user that their input was invalid
        cin.clear();                        // buffer is cleared so that a new input can be stored
        cin.ignore(10000,'\n');             // ignores '\n' for x (1000) characters
    }

    switch (user_input)
    {
        case 1: // add a product
            if(budget < 2.99) // user must afford cheapest product
            {
                cout << "Your budget is insufficient to add more products." << endl; 
            } 
            else
            {
                cout << "Add Product:\n" 
                        << "A) Cheetos\n"
                        << "B) Oreos\n"
                        << "C) Coffee\n"
                        << "D) Slurpee"
                        << endl;
        
                cin >> product; 
                if(cin.fail() || product < 'A' || product > 'D') 
                { 
                    cout << "Invalid input." << endl;    // outputs to the user that their input was invalid
                    cin.clear();                        // buffer is cleared so that a new input can be stored
                    cin.ignore(10000,'\n');             // ignores '\n' for x (1000) characters
                }
            budget = new_budget;
            cart = addProduct(cart, product, budget);
            budget = budget - beforeTax (cart); 
            }   
        break;
        case 2: // remove a product
            cout << "Enter the product name to be removed from the cart: " << endl;
            cin >> remove_product; 

            if (cart.size() == 0)
            {
                cout << "Cart is empty." << endl;
            }
            else
            { 
                if ((remove_product != "Cheetos") && (remove_product != "Oreos") && (remove_product != "Coffee") && (remove_product != "Slurpee"))
                {
                    cout << "Product Name not found." << endl;    // outputs to the user that their input was invalid
                }
                else if (remove_product == "Cheetos")
                {
                    
                    cart = removeProduct(cart, remove_product, budget); 
                    budget = budget + cheetos;  // add back the product cost to the budget

                }
                else if (remove_product == "Oreos")
                {
                    
                    cart = removeProduct(cart, remove_product, budget); 
                    budget = budget + oreos;  // add back the product cost to the budget
                }
                else if (remove_product == "Coffee")
                {
                    
                    cart = removeProduct(cart, remove_product, budget); 
                    budget = budget + coffee;  // add back the product cost to the budget
        
                }
                else if (remove_product == "Slurpee")
                {
                    
                    cart = removeProduct(cart, remove_product, budget); 
                    budget = budget + slurpee;  // add back the product cost to the budget
        
                }
        break;
        case 3: // checkout
            if (cart.size() == 0)
                {
                // returns user to menu
                cout << "Cart is empty." << endl;
                }
            else 
            {
                checkout(cart);
                return 1;
            }
        case 4: // exit program
            if (user_input == 4)
            {
                cout << "Thank you! Please visit again." << endl; // goodbye to user
                return 1; // ends program
            }
            }
    }


} while (user_input != 4);
}


vector<string> addProduct(vector <string> cart, char product, double budget)  // couts statement and then adds the product to the vector
{
    switch (product)
    {
    case 'A': 
        cout << "Cheetos added to cart." << endl; // prints confirmation 
        cart.push_back("Cheetos"); // adds product to end of list
        break;
    case 'B':
        cout << "Oreos added to cart." << endl; // prints confirmation 
        cart.push_back("Oreos"); // adds product to end of list
        break;

    case 'C':
        cout << "Coffee added to cart." << endl; // prints confirmation
        cart.push_back("Coffee"); // adds product to end of list
        break;
    
    case 'D':
        cout << "Slurpee added to cart." << endl; // prints confirmation
        cart.push_back("Slurpee"); // adds product to end of list
        break; 
    }
    return cart;
}

vector<string> removeProduct(vector<string> cart, string product, double budget)
{
    // products that aren't being removed stored in temp_cart
    // will be stored as removed items will not be added to temp
    vector<string> temp_cart;

    // will continue until the item is removed
    bool item_removed = false;
    
    int count = 0;
    for (int i = 0; i < cart.size(); i++)
    {
        if (cart.at(i) == product)
        {
            count++;

        }
    }

    if (count == 0)
    {
        cout << "Product Name not found." << endl;
    }

    else if (!item_removed) // if its true the item isn't removed
    {
            if (product == "Cheetos") 
            {
                    cout << "Cheetos removed from cart." << endl; 

                    for (int i = 0; i < cart.size(); i++)
                    {
                        if ( cart.at(i) != "Cheetos" || item_removed == true)
                        {
                            temp_cart.push_back(cart.at(i)); 
                        }
                        else
                        {
                            item_removed = true;
                        }
                    }
            }
            else if (product == "Oreos") // oreos
            {
                    cout << "Oreos removed from cart." << endl; 
                    
                    for (int i = 0; i < cart.size(); i++)
                    {
                        if ( cart.at(i) != "Oreos" || item_removed == true)
                        {
                            temp_cart.push_back(cart.at(i)); 
                        }
                        else
                        {
                            item_removed = true;
                        }
                    }
            }
            else if (product == "Coffee")
            {
                    cout << "Coffee removed from cart." << endl; 
                    
                    for (int i = 0; i < cart.size(); i++)
                    {
                        if ( cart.at(i) != "Coffee" || item_removed == true)
                        {
                            temp_cart.push_back(cart.at(i)); // items that arent coffee stored here
                        }
                        else
                        {
                            item_removed = true;
                        }
                    }
            }
            else if (product == "Slurpee")
            {

                    cout << "Slurpee removed from cart." << endl; 
                    for (int i = 0; i < cart.size(); i++)
                    {
                        if ( cart.at(i) != "Slurpee" || item_removed == true)
                        {
                            temp_cart.push_back(cart.at(i)); 
                        }
                        else
                        {
                            item_removed = true;
                        }
                    }
            }
    return temp_cart;
}
}


double beforeTax (vector<string> cart)
{
    // total to be taken from budget 
    double total = 0;
    // product prices
    const double cheetos = 2.99;
    const double oreos = 3.39;
    const double coffee = 3.79;
    const double slurpee = 4.29;

    // for each value in the cart, the total will be added up for each product
    for(int i = 0; i < cart.size(); i++)
    {
        if (cart[i] == "Cheetos") // cheetos
        {

            total = total + cheetos; 

        }
        else if (cart[i] == "Oreos") // oreos
        {

            total = total + oreos; 

        }
        else if (cart[i] == "Coffee") // coffee
        {

            total = total + coffee; 

        }
        else if (cart[i] == "Slurpee") // slurpee
        {

            total = total + slurpee; 

        }
        
    }
    return total;
}

double addSum(vector<string> cart)
{
    // total to be taken from budget 
    double total = 0;
    // product prices
    const double cheetos = 2.99 * (1 + 0.09); 
    const double oreos = 3.39 *(1 + 0.09);
    const double coffee = 3.79 * (1 + 0.09);
    const double slurpee = 4.29 * (1 + 0.09); 

    // for each value in the cart, the total will be added up for each product
    for(int i = 0; i < cart.size(); i++)
    {
        if (cart[i] == "Cheetos") // cheetos
        {

            total = total + cheetos; 

        }
        else if (cart[i] == "Oreos") // oreos
        {

            total = total + oreos; 

        }
        else if (cart[i] == "Coffee") // coffee
        {

            total = total + coffee; 

        }
        else if (cart[i] == "Slurpee") // slurpee
        {

            total = total + slurpee; 

        }
        
    }
    return total;
}

void checkout (vector<string> cart)
{
        cout << "Your cart has the following products: " << endl; 
        // loop through the cart, listing each one by one
        for(int i = 0; i < cart.size(); i++)
        {
            cout << cart[i] << endl; // prints each item
        }
        double total = addSum(cart); // sums up entire cart
        cout << "Total amount: $" << fixed << setprecision(3) << total << endl; // ensures 3 decimal places
        //program terminates
        cout << "Thank you! Please visit again. " << endl;
}