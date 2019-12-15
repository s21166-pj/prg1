#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

void show_ballance();
void mafia_loan();
void menu();
void roulette_game();
void win_bet_summary();
void lose_bet_summary();
void rules_help();

int const min_loan = 10000;
int const max_loan = 200000;
int const owe_multiplyer = -7;
int const min_no_roulette_bet = 500;
int const max_no_roulette_bet = 3000;
int const min_color_roulette_bet = 1000;
int const max_color_roulette_bet = 100000;

int balance = 0;
int amount_owed = 0;
int bet = 0;

int main()
{
	mafia_loan();

	show_ballance();

	srand(time(NULL));
	menu();

	return 0;
}
void mafia_loan()
{	int temp_balance = 0;
	cout << "How much money would you like to borrow?" << endl;
	cout << "Min = " << min_loan << "$"  << "   |   " << " Max = " << max_loan << "$" << endl;
	while(1){
		cin >> temp_balance;
			if (temp_balance >= min_loan && temp_balance <= max_loan) {
				balance += temp_balance;
				amount_owed = owe_multiplyer*temp_balance;
				break;
			} else if (temp_balance < min_loan) {
				cout << "That's not enough... MORE!" << endl;
			} else if (temp_balance > max_loan) {
				cout << "That's too much... LESS!" << endl;
				}
		}
}
void menu()
{
	char game_choice;

	cout << "\n";
	cout << "Which game would you like to choose?" << endl;
	cout << "[B]lack Jack or [R]oulette?" << endl;
	cin >> game_choice;

	if (tolower(game_choice) == 'b') {
		cout << "Black jack" << endl;
		//black_jack_game();
	} else if (tolower(game_choice) == 'r') {
		cout << "Ruletka" << endl;
		roulette_game();
	} else {
		cout << "Please choose only from available games [B] or [R]" << endl;
	}
}
void roulette_game()
{
	int number;
	int random;
	char player_choice;
	vector <int> red_numbers = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	vector <int> black_numbers = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

	random = rand() % 37;
	cout << "your random number from 0 - 36 is " << random << endl;
	cout << "Welcome to Roulette!" << endl;
	cout << "What would you like to bet on?" << endl;
	cout << "[N]umber ? Colour [R]ed or [B]lack ? For rules press [H]elp or get back to [M]enu"<< endl;
	while(1) {
		cin >> player_choice;

		if (tolower(player_choice) == 'n') {
			cout << "Choose your lucky number from 0 - 36!" << endl;
			while(1) {
				cin >> number;
				cout << "How much would you like to bet?" << endl;
				cout << "Min bet: " << min_no_roulette_bet << "$" << "   |   " << "Max bet: " << max_no_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_no_roulette_bet && bet <= max_no_roulette_bet) {
					if (number == random){
					bet = bet*35;
					win_bet_summary();
					break;
					} else {
					lose_bet_summary();
					}
				} else if (bet < min_no_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_no_roulette_bet) {
					cout << "That's too much!" << endl;
				}
			}
		} else if (tolower(player_choice) == 'r') {
			cout << "How much would you like to bet?" << endl;
			cout << "Min bet: " << min_color_roulette_bet << "$" << "   |   " << "Max bet: " << max_color_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_color_roulette_bet && bet <= max_color_roulette_bet) {
					if (count(red_numbers.begin(), red_numbers.end(), random)) {
					bet = bet*2;
					win_bet_summary();
					} else {
					lose_bet_summary();
					}
				} else if (bet < min_color_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_color_roulette_bet) {
					cout << "That's too much!" << endl;
				}
		} else if (tolower(player_choice) == 'b') {
			cout << "How much would you like to bet?" << endl;
			cout << "Min bet: " << min_color_roulette_bet << "$" << "   |   " << "Max bet: " << max_color_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_color_roulette_bet && bet <= max_color_roulette_bet) {
					if (count(black_numbers.begin(), black_numbers.end(), random)) {
						bet = bet*2;
						win_bet_summary();
					} else {
						lose_bet_summary();
					}
				} else if (bet < min_color_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_color_roulette_bet) {
					cout << "That's too much!" << endl;
				}
		} else if (tolower(player_choice) == 'h') {
			//rules_help();
		} else if (tolower(player_choice) == 'm') {
			menu();
		} else {
			cout << "Wrong command!" << endl;
		}
	}
}
void show_ballance()
{
	cout << "Balance: " << balance << endl;
	cout << "You owe: " << amount_owed << endl;
}
void win_bet_summary()
{
	balance += bet;
	amount_owed += bet;
	cout << "Wygrałeś " << bet << "$ !" << endl;
	cout << "Balance: " <<  balance << "$" << endl;
	cout << "You owe: " << amount_owed << "$" << endl;
	bet = 0;
}
void lose_bet_summary()
{
	balance -= bet;
	amount_owed -= bet;
	cout << "Przegrałeś " << bet << "$ :(" << endl;
	cout << "Balance: " <<  balance << "$" << endl;
	cout << "You owe: " << amount_owed << "$" << endl;
	bet = 0;
}
void rules_help()
{
	//if (game_choice == "r" || game_choice == "R")
}
