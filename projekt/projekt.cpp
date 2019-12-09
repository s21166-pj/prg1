#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int player_money(int &balance, int  &amount_owed);
void menu();
void roulette_game(int &balance, int &amount_owed);

int main()
{
	int balance = 0;
	int amount_owed = 0;

	player_money(balance, amount_owed);

	cout << "Balance: " <<  balance << endl;
	cout << "You owe: " << amount_owed << endl;

	menu();


	return 0;
}
int player_money(int &balance, int &amount_owed)
{	int temp_balance = 0;
	cout << "How much money would you like to borrow?" << endl;
	cout << "Min = 10 000$    |    Max = 100 000$" << endl;
	while(1){
		cin >> temp_balance;
			if(temp_balance >= 10000 && temp_balance <= 100000){
				balance += temp_balance;
				amount_owed = -2*temp_balance;
				break;
			}else if(temp_balance < 10000){
				cout << "That's not enough... MORE!" << endl;
			}else if(temp_balance > 100000){
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

	if(game_choice == "B" || game_choice == "b"){
		cout << "Black jack" << endl;
		//black_jack_game();
	}else if(game_choice == "R" || game_choice == "r"){
		cout << "Ruletka" << endl;
		roulette_game(int &balance, int &amout_owed);
	}else{
		cout << "Please choose only from available games ([B] or [R])" << endl;
	}
}
void roulette_game(int &balance, int &amount_owed)
{
	int random;
	int bet;
	char player_choice;

	cout << "Welcome to Roulette!\n";
	cout << "What would you like to bet on?\n"
	cout << "[N]umber ? Colour [R]ed or [B]lack ? For rules press [H]elp" << endl;
	cin >> player_choice;
	tolower(player_choice);
	if(players_choice == "n"){
	cout << "to kurwa działa i jest małe";
	}


	cout << "How much would you like to bet?" ;
	cin >> bet;


}

