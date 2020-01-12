#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <vector>
#include <unistd.h>

using namespace std;

void show_ballance();
void mafia_loan();
void debt_collector();
void menu();
void roulette_game();
void win_bet_summary();
void lose_bet_summary();
void rules_help();
void blackjack_game();
void blackjack_logic();
bool has_been_dealt();

int const MIN_LOAN = 10000;
int const MAX_LOAN = 200000;
int const OWE_MULTIPLYER = -7;
int const ROULETTE_MIN_NUMBER_BET = 500;
int const ROULETTE_MAX_NUMBER_BET = 3000;
int const ROULETTE_MIN_COLOUR_BET = 1000;
int const ROULETTE_MAX_COLOUR_BET = 100000;
int const ROULETTE_NUMBER_WIN_MULTIPLYER = 35;
int const ROULETTE_COLOUR_WIN_MULTIPLYER = 2;
int const BLACKJACK_MIN_BET = 5000;
int const BLACKJACK_MAX_BET = 100000;
int const BLACKJACK_BET_MULTIPLYER = 2;
int const MAX_CARDS = 5;

int balance = 0;
int amount_owed = 0;
int bet = 0;
bool blackjack_rules = true;

int main()
{
	srand(time(NULL));
	cout << "Welcome to Badysiak Cassino!" << endl;

	mafia_loan();

	menu();

	return 0;
}
void mafia_loan()
{	
	int temp_balance = 0;
	cout << "How much money would you like to borrow?" << endl;
	cout << "Min = " << MIN_LOAN << "$"  << "   |   " << " Max = " << MAX_LOAN << "$" << endl;
	while(1){
		cin >> temp_balance;
			if (temp_balance >= MIN_LOAN && temp_balance <= MAX_LOAN) {
				balance += temp_balance;
				amount_owed += OWE_MULTIPLYER*temp_balance;
				break;
			} else if (temp_balance < MIN_LOAN) {
				cout << "That's not enough... MORE!" << endl;
			} else if (temp_balance > MAX_LOAN) {
				cout << "That's too much... LESS!" << endl;
				}
		}
	show_ballance();
}
void debt_collector()
{
	char final_decision;
	int paying_debt;
	while(1) {
		system("clear");
		cout << "So.... You came here to pay your debt?  *sigh*..." << endl;
		cout << "How much are you willing to pay ?" << endl;
		cout << "If you want to pay part of it, remember to leave some money to play > 10 000$" << endl;
		show_ballance();
		cin >> paying_debt;
		if (paying_debt > balance) {
			cout << "You don't have that much money!" << endl;
		} else if ((balance-paying_debt) <= MIN_LOAN) {
			cout << "You need to leave yourself at least " << MIN_LOAN << "$" << endl;
		} else if (paying_debt < balance && (balance-paying_debt) >= MIN_LOAN) {
			balance -= paying_debt;
			amount_owed += paying_debt;
			cout << "Now your balance and debt look like this:" << endl;
			show_ballance();
			if (amount_owed >= 0) {
				cout << "Congratulations ! You've paid your debt and you can play on your own account!" << endl;
				cout << "If you had bad luck, don't hessitate to borrow money from us ^.-" << endl;
				cout << "Do you want to keep playing? [Y]es or [N]o" << endl;
				cin >> final_decision;
				if (tolower(final_decision) == 'n') {
					exit(0);
				}
			} else {
				sleep(3);
				break;	
			}
		}
	}
}
void menu()	// Menu withc choices of games and availability to borrow more money if we lose all
{
	char game_choice;
	while(1) {
		cout << "\n";
		cout << "Which game would you like to choose?" << endl;
		cout << "[B]lack Jack or [R]oulette?" << endl;
		cout << "\n";
		cout << "Borrow more money [L]" << endl;
		cout << "Pay your debt [P]" << endl; 
		cin >> game_choice;

		if (tolower(game_choice) == 'b') {
			system("clear");
			blackjack_game();
		} else if (tolower(game_choice) == 'r') {
			system("clear");
			roulette_game();
		} else if (tolower(game_choice) == 'l') {
			system("clear");
			mafia_loan();
		} else if (tolower(game_choice) == 'p') {
			system("clear");
			debt_collector();
		} else {
			cout << "Please choose only from available games [B]lackJack or [R]oulette" << endl;
		}
	}
}
void roulette_strip(int random)
{
	vector <int> strip = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};
    int timer = 1;
    int refreshing_strip = 8;
    int rand_index;
    int x = 5;
    vector <int>::iterator itr = find(strip.begin(), strip.end(), random);
 
    if (itr != strip.cend()) {
        rand_index = distance(strip.begin(), itr);
    }
   
    rand_index -= x;
    if (rand_index < 0) rand_index += strip.size();
 
    cout << endl;
    for(int i=0; i<refreshing_strip; i++) {
        system("clear");
        for(int j=0; j<11; j++) {
            int idx = (rand_index+j) % strip.size();
            cout << strip[idx] << "\t";
        }
        cout << endl;
        for(int j=0; j<11; j++) {
            if (j == 5) cout << "O";
            else cout << " ";
            cout << "\t";
        }
        if (i == refreshing_strip - 2) {
            rand_index += 7;
        } else {
            rand_index += 5;
        }
        sleep(timer);
        cout << endl;
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
				cout << "Min bet: " << ROULETTE_MIN_NUMBER_BET << "$" << "   |   " << "Max bet: " << ROULETTE_MAX_NUMBER_BET << "$" << endl;
				cin >> bet;
				if (bet >= ROULETTE_MIN_NUMBER_BET && bet <= ROULETTE_MAX_NUMBER_BET) {
					roulette_strip(random);
					if (number == random){
						bet = bet*ROULETTE_NUMBER_WIN_MULTIPLYER;
						win_bet_summary();
						break;
						} else {
							lose_bet_summary();
							break;
						}
				} else if (bet < ROULETTE_MIN_NUMBER_BET) {
					cout << "Not enough! More!" << endl;
				} else if (bet > ROULETTE_MAX_NUMBER_BET) {
					cout << "That's too much!" << endl;
				}
			} 	
		// Handling bet on RED logic
		} else if (tolower(player_choice) == 'r') {
			system("clear");
			while(1) {
				cout << "How much would you like to bet?" << endl;
				cout << "Min bet: " << ROULETTE_MIN_COLOUR_BET << "$" << "   |   " << "Max bet: " << ROULETTE_MAX_COLOUR_BET << "$" << endl;
				cin >> bet;
					if ( bet <= balance) {
						if (bet >= ROULETTE_MIN_COLOUR_BET && bet <= ROULETTE_MAX_COLOUR_BET) {
							if (count(red_numbers.begin(), red_numbers.end(), random)) {
								bet = bet*ROULETTE_COLOUR_WIN_MULTIPLYER;
								win_bet_summary();
								break;
								} else {
									cout << "Ball landed on black :(" << endl;
									lose_bet_summary();
									break;
								}
						} else if (bet < ROULETTE_MIN_COLOUR_BET) {
							cout << "Not enough! More!" << endl;
						} else if (bet > ROULETTE_MAX_COLOUR_BET) {
							cout << "That's too much!" << endl;
						}
					} else {
						cout << "You don't have enough money!" << endl;
					}
				}
				// Handling bet on BLACK logic
		} else if (tolower(player_choice) == 'b') {
			system("clear");
			while(1) {
				cout << "How much would you like to bet?" << endl;
				cout << "Min bet: " << ROULETTE_MIN_COLOUR_BET << "$" << "   |   " << "Max bet: " << ROULETTE_MAX_COLOUR_BET << "$" << endl;
				cin >> bet;
				if (bet <= balance) {
					if (bet >= ROULETTE_MIN_COLOUR_BET && bet <= ROULETTE_MAX_COLOUR_BET) {
						if (count(black_numbers.begin(), black_numbers.end(), random)) {
							bet = bet*ROULETTE_COLOUR_WIN_MULTIPLYER;
							win_bet_summary();
							break;
						} else {
							cout << "Ball landed on Red :(" << endl;
							lose_bet_summary();
							break;
						}
					} else if (bet < ROULETTE_MIN_COLOUR_BET) {
						cout << "Not enough! More!" << endl;
					} else if (bet > ROULETTE_MAX_COLOUR_BET) {
						cout << "That's too much!" << endl;
					}
				} else {
					cout << "You don't have enough money!" << endl;
				}
			}
		} else if (tolower(player_choice) == 'h') {
			rules_help();
		} else if (tolower(player_choice) == 'm') {
			menu();
		} else {
			cout << "Wrong command!" << endl;
		}
	}
}
void show_ballance()
{
	cout << "Balance: " << balance << "$" << endl;
	cout << "You owe: " << amount_owed << "$" << endl;
}
void win_bet_summary()
{
	balance += bet;
	cout << "Wygrałeś " << bet << "$!" << endl;
	show_ballance();
	bet = 0;
}
void lose_bet_summary()
{
	balance -= bet;
	cout << "Przegrałeś " << bet << "$ :(" << endl;
	show_ballance();
	bet = 0;
}
void rules_help()
{
	system("clear");
	cout << "Playing on [N]umber - You choose number from 0 to 35 and winrate is 35/1" << endl;
	cout << "By playin on [R]eds or [B]lacks you win only when ball lands on specific colour" << endl;
	cout << "(nearly half of roulette is either black or red (except number 0 which is green))" << endl;
	cout << "\n";
}
// struct Cards
// {
// 	int value;
// 	char suit;
	
// };
	// checks if card from deck has been used already
bool has_been_dealt(int random_suit,int random_card,int player_cards[] ,int dealer_cards[])
{
	for(int i = 0; i>MAX_CARDS*2; i=i+2) {
		if (player_cards[i] == random_suit) {
			if (player_cards[i+1] == random_card) {
				return true;
			}
		}
		if (dealer_cards[i] == random_suit) {
			if (dealer_cards[i+1] == random_card) {
				return true;
			}
		}	
	}
	return false;
}
void blackjack_logic()
{
	int dealer_total = 0;
	int player_total = 0;

	int random_card;
	int random_suit;

	int player_cards[MAX_CARDS*2];
	int dealer_cards[MAX_CARDS*2];
	// zeroing arrays
	for(int i = 0; i<MAX_CARDS*2; i++) {
		player_cards[i] = -1;
		dealer_cards[i] = -1;
	}
	int player_displayed_cards = 2;
	int dealer_displayed_cards = 2;
	
	bool player_turn = true;
	bool dealer_turn = false;

	char bj_game_choice = 0;
	char bj_play_again;

	string deck [13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jokey", "Queen", "King", "Ace",};	
	string suit [4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	int value [13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
	
	// rolling new cards -> checking if has_been_dealt and if not, assing card to a player
	for(int i=0; i<MAX_CARDS*2; i=i+2) {
		do {	
			random_suit = rand() % 4;
			random_card = rand() % 13;
		} while (has_been_dealt(random_suit, random_card, player_cards, dealer_cards));
			player_cards[i] = random_suit;	
			player_cards[i+1] = random_card;
	}
	// rolling new card for dealer ( has been dealt checks if card has been given already)
	for(int i=0; i<MAX_CARDS*2; i=i+2) {
		do {
			random_suit = rand() % 4;
			random_card = rand() % 13;
		} while (has_been_dealt(random_suit, random_card, player_cards, dealer_cards));
			dealer_cards[i] = random_suit;
			dealer_cards[i+1] = random_card;
	}
	
	
	while(1) {
		player_total = 0;
		dealer_total = 0;
		// Displaying player max_no_cards (default=2) and summing up their value
		cout << "Your cards: ";
		for(int i=0; i<player_displayed_cards*2; i=i+2) {
			cout << deck[player_cards[i+1]] << " of " << suit[player_cards[i]];
			if (i<player_displayed_cards*2-2) {
				cout << " and ";
			}
			player_total = player_total + value[player_cards[i+1]];
		}
		cout << endl << "You: " << player_total << endl;
		
		// Displaying dealer cards and summing up total value
		cout << "Dealer cards: ";
		for(int i=0; i<dealer_displayed_cards*2; i=i+2) {
			cout << deck[dealer_cards[i+1]] << " of " << suit[dealer_cards[i]];
			if (i<dealer_displayed_cards*2-2) {
				cout << " and ";
			}
			dealer_total = dealer_total + value[dealer_cards[i+1]];
		}
		cout << endl << "Dealer: " << dealer_total << endl;
		
		// checking first deal of cards
		if(player_total == 21 && dealer_total == 21) {
			cout << "It's a draw!" << endl;
			break;
		} else if (player_total == 21) {
			cout << "You've got BlackJack!" << endl;
			win_bet_summary();
			break;
		} else if (dealer_total == 21) {
			lose_bet_summary();
			break;
		}
		if (player_turn) {
			cout << "[S]tay or [H]it" << endl;
			cin >> bj_game_choice;
			if (tolower(bj_game_choice) == 'h') {
				player_displayed_cards += 1;
				int new_sum = player_total + value[player_cards[player_displayed_cards*2-1]];
				if ( new_sum > 21) {
					player_turn = false;
				}
			} else {
				player_turn = false;
				dealer_turn = true;
			}	
		}
		if (dealer_turn)  {
			if(dealer_total <= 16 && dealer_displayed_cards < MAX_CARDS) {
				dealer_displayed_cards += 1;
			} else {
				dealer_turn = false;
			}
		}
		if(tolower(bj_game_choice) == 'h') {
		    if (player_total > 21) {
				lose_bet_summary();
				break;
			}
		}
		if(tolower(bj_game_choice) == 's') {
			if (!dealer_turn) {
				if (dealer_total > 21) {
					win_bet_summary();
					break;
				} else if (player_total > dealer_total) {
					win_bet_summary();
					break;
				} else if (player_total < dealer_total) {
					lose_bet_summary();
					break;
				} else if (player_total == dealer_total) {
					cout << "PUSH" << endl;
					break;
				}
			}
		}
				
	}
	cout << endl;
	cout << "Would you like to play again [Y]es or [N]o?" << endl;
	cin >> bj_play_again;
	if ( tolower(bj_play_again) == 'n') {
		system("clear");
		menu();
	}
}	
void blackjack_game()
{	
	cout << "Welcome to BlackJack!" << endl;
	cout << "\n";
	if (blackjack_rules == true) {
		cout << "It's a classic game, sometimes called '21'" << endl;
		cout << "To win you have to have more than Croupier, but up to 21 points" << endl;
		cout << "You lose either exceeding 21 points or having less than Cruopier at the end" << endl;
		cout << "When you have the same amount of points in cards it's a draw" << endl;
		cout << "Winning grants you 2/1 winnings :)" << endl;
		cout << "\n";
		blackjack_rules = false;
	}
	while(1) {
		cout << "How much would you like to bet?" << endl;
		cout << "Min bet: " << BLACKJACK_MIN_BET << "$" << "   |   " << "Max bet: " << BLACKJACK_MAX_BET << "$" << endl;
		cin >> bet;
		if ( bet <= balance) {
			if (bet >= BLACKJACK_MIN_BET && bet <= BLACKJACK_MAX_BET) {
				blackjack_logic();
			} else if (bet < BLACKJACK_MIN_BET) {
				cout << "Not enough! More!" << endl;
			} else if (bet > BLACKJACK_MAX_BET) {
				cout << "That's too much!" << endl;
			}
		} else {
			cout << "You don't have enough money!" << endl;
		}
	}
}