#include <iostream>

using namespace std;

int main () {
    int iron_coins;
    int leftover_iron;

    int bronze_coins;
    int silver_coins;
    int gold_coins;

    cout << "Enter the number of iron coins: " << endl;
    cin >> iron_coins;

//converting to gold, and calculating what is leftover
    gold_coins = iron_coins / (23 * 13 * 3);
    leftover_iron = iron_coins % (23 * 13 * 3);

//converting leftover to silver, calculating what is leftover
    silver_coins = leftover_iron / (13 * 3);
    leftover_iron = iron_coins % (13 * 3);

//converting leftover to bronze, calculating what is leftover
    bronze_coins = leftover_iron / (3);
    leftover_iron = iron_coins % (3);

//remainder are iron coins
    

    cout << gold_coins << " gold coin(s) " << silver_coins << " silver coin(s) " << bronze_coins << " bronze coin(s) " << leftover_iron << " iron coin(s) " << endl;
    
}