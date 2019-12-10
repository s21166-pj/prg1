#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
using namespace std;

int player_money();
void menu();
void roulette_game();


int balance = 0;
int amount_owed = 0;

int main()
{

	player_money();

	cout << "Balance: " <<  balance << endl;
	cout << "You owe: " << amount_owed << endl;

	menu();


	return 0;
}
int player_money()
{	int temp_balance = 0;
	cout << "How much money would you like to borrow?" << endl;
	cout << "Min = 10 000$    |    Max = 100 000$" << endl;
	while(1){
		cin >> temp_balance;
			if (temp_balance >= 10000 && temp_balance <= 100000) {
				balance += temp_balance;
				amount_owed = -7*temp_balance;
				break;
			} else if (temp_balance < 10000) {
				cout << "That's not enough... MORE!" << endl;
			} else if (temp_balance > 100000) {
				cout << "That's too much... LESS!" << endl;
				}
		}
}
void menu()
{
	string game_choice;

	cout << "\n";
	cout << "Which game would you like to choose?" << endl;
	cout << "[B]lack Jack or [R]oulette?" << endl;
	cin >> game_choice;

	if (game_choice == "b" || game_choice == "B") {
		cout << "Black jack" << endl;
		//black_jack_game();
	} else if (game_choice == "r" || game_choice == "R") {
		cout << "Ruletka" << endl;
		roulette_game();
	} else {
		cout << "Please choose only from available games ([B] or [R])" << endl;
	}
}
void roulette_game()
{
	int number;
	int random;
	int bet;
	string player_choice;
	int red_numbers[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	int black_numbers[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

	srand(time(NULL));
	random = rand() % 37;
	cout <<  "your random number from 0 - 36 is" << random << endl;
	cout << "Welcome to Roulette!" << endl;
	cout << "What would you like to bet on?" << endl;
	cout << "[N]umber ? Colour [R]ed or [B]lack ? For rules press [H]elp" << endl;
	while(1) {
		cin >> player_choice;

		if (player_choice == "n" || player_choice == "N") {
			while(1) {
				cout << "Choose your lucky number from 0 - 36!" << endl;
				cin >> number;
				cout << "How much would you like to bet?" << endl;
				cout << "Min bet: 500$  |  Max bet: 3000$" << endl;
				cin >> bet;
				if (bet >= 500 && bet <= 3000) {
					if (number == random){
					bet = bet*35;
					balance += bet;
					amount_owed += bet;
					cout << "Wygrałeś " << bet << "!" << endl;
					cout << "Balance: " <<  balance << endl;
					cout << "You owe: " << amount_owed << endl;
					}
				} else if (bet < 500) {
					cout << "Not enough! More!" << endl;
				} else if (bet > 3000) {
					cout << "That's too much!" << endl;
				}
			}
		}
	}
}

