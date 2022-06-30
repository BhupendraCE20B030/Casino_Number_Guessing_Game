#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules()
{
    system("cls");
    cout << "\t\t******CASINO NUMBER GUESSING RULES!******" << endl;
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}
int main()
{
    string player_name;
    int balance, betting_amount, guess, dice;
    char choice;
    srand(time(0));
    cout << "\n\t\t******WELCOME TO CASINO WORLD******\n\n";
    cout << "\n\n What's your Name : ";
    getline(cin, player_name);
    cout << "\n\nEnter the starting balance to play game : $ ";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\n Your current balance is " << balance << " $\n";
        // For the batting balance.
        do
        {
            cout << "Hey " << player_name << ", enter amount to be bet : ";
            cin >> betting_amount;
            if (betting_amount > balance)
            {
                cout << "Betting Balance can't be more then current balance!\n\n Re-enter Balance\n";
            }
        } while (betting_amount > balance);
        // For the player's number
        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     << "Re-enter number:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand()%10 +1;
        if(dice==guess){
                       cout << "\n\nYou are in luck!! You have won Rs." << betting_amount * 10;
            balance = balance + betting_amount * 10; 
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< betting_amount <<"\n";
            balance = balance - betting_amount;
        }
                cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<player_name<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}