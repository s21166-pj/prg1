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
void blackjack_game();

int const min_loan = 10000;
int const max_loan = 200000;
int const owe_multiplyer = -7;
int const min_no_roulette_bet = 500;
int const max_no_roulette_bet = 3000;
int const min_color_roulette_bet = 1000;
int const max_color_roulette_bet = 100000;
int const roulette_number_win_multiplyer = 35;
int const roulette_colour_win_multiplyer = 2;
int const blackjack_min_bet = 5000;
int const blackjack_max_bet = 100000;

int balance = 0;
int amount_owed = 0;
int bet = 0;

int main()
{
	srand(time(NULL));
	mafia_loan();

	show_ballance();

		menu();

	return 0;
}
void mafia_loan()
{	
	int temp_balance = 0;
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
void menu()	// Menu withc choices of games and availability to borrow more money if we lose all
{
	char game_choice;

	cout << "\n";
	cout << "Which game would you like to choose?" << endl;
	cout << "[B]lack Jack or [R]oulette?" << endl;
	cout << "If you would like to borrow more money press [L]" << endl;
	cin >> game_choice;

	if (tolower(game_choice) == 'b') {
		system("clear");
		blackjack_game();
	} else if (tolower(game_choice) == 'r') {
		system("clear");
		roulette_game();
	} else if (tolower(game_choice) == 'l') {
		system("clear");
		blackjack_game();
	} else {
		cout << "Please choose only from available games [B]lackJack or [R]oulette" << endl;
	}
}
void roulette_game()
{
	int number;
	int random;
	char player_choice;
	vector <int> red_numbers = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	vector <int> black_numbers = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};

	
	cout << "Welcome to Roulette!" << endl;
	while(1) {
		random = rand() % 37;
		cout << "your random number from 0 - 36 is " << random << endl;
		cout << "What would you like to bet on?" << endl;
		cout << "[N]umber ? Colour [R]ed or [B]lack ? For rules press [H]elp or get back to [M]enu"<< endl;
		cin >> player_choice;

			// Handling bet on number logic
		if (tolower(player_choice) == 'n') {
			system("clear");
			cout << "Choose your lucky number from 0 - 36!" << endl;
			cin >> number;
			while(1) {
				cout << "How much would you like to bet?" << endl;
				cout << "Min bet: " << min_no_roulette_bet << "$" << "   |   " << "Max bet: " << max_no_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_no_roulette_bet && bet <= max_no_roulette_bet) {
					if (number == random){
						bet = bet*roulette_number_win_multiplyer;
						win_bet_summary();
						break;
						} else {
							lose_bet_summary();
							break;
						}
				} else if (bet < min_no_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_no_roulette_bet) {
					cout << "That's too much!" << endl;
				}
			} 	// Handling bet on RED logic
		} else if (tolower(player_choice) == 'r') {
			system("clear");
			while(1) {
			cout << "How much would you like to bet?" << endl;
			cout << "Min bet: " << min_color_roulette_bet << "$" << "   |   " << "Max bet: " << max_color_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_color_roulette_bet && bet <= max_color_roulette_bet) {
					if (count(red_numbers.begin(), red_numbers.end(), random)) {
						bet = bet*roulette_colour_win_multiplyer;
						win_bet_summary();
						break;
						} else {
							lose_bet_summary();
							break;
						}
				} else if (bet < min_color_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_color_roulette_bet) {
					cout << "That's too much!" << endl;
				}
			}	// Handling bet on BLACK logic
		} else if (tolower(player_choice) == 'b') {
			system("clear");
			while(1) {
			cout << "How much would you like to bet?" << endl;
			cout << "Min bet: " << min_color_roulette_bet << "$" << "   |   " << "Max bet: " << max_color_roulette_bet << "$" << endl;
				cin >> bet;
				if (bet >= min_color_roulette_bet && bet <= max_color_roulette_bet) {
					if (count(black_numbers.begin(), black_numbers.end(), random)) {
						bet = bet*roulette_colour_win_multiplyer;
						win_bet_summary();
						break;
					} else {
						lose_bet_summary();
						break;
					}
				} else if (bet < min_color_roulette_bet) {
					cout << "Not enough! More!" << endl;
				} else if (bet > max_color_roulette_bet) {
					cout << "That's too much!" << endl;
				}
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
	cout << "Wygrałeś " << bet << "$!" << endl;
	show_ballance();
	bet = 0;
}
void lose_bet_summary()
{
	balance -= bet;
	amount_owed -= bet;
	cout << "Przegrałeś " << bet << "$ :(" << endl;
	show_ballance();
	bet = 0;
}
void rules_help()
{
	//if (tolower(game_choice == 'r')
}
struct Cards
{
	int value;
	char suit;
	
};
void blackjack_game()
{
	int dealer_hand = 0;
	int player_hand = 0;
	
	int random_card;
	int random_suit;

	string deck [4][13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jokey", "Queen", "King", "Ace",
							"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jokey", "Queen", "King", "Ace",
							"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jokey", "Queen", "King", "Ace",
							"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jokey", "Queen", "King", "Ace",};	

	string suit [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	int value [13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

	cout << "Welcome to BlackJack!" << endl;
	while(1) {
		random_card = rand() % 13;
		random_suit = rand() % 4;
		cout << "How much would you like to bet?" << endl;
		cout << "Min bet: " << blackjack_min_bet << "$" << "   |   " << "Max bet: " << blackjack_max_bet << "$" << endl;
		
	}
}