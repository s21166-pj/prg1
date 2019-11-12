#include <iostream>
using namespace std;
// Badysiak Paweł
// Wadas Michał
int main(){
	cout << "Podaj liczbe ";
	int i;
	int j;
	j = 0;
	cin >> i;
	while(i != 0){
		cout << "Podaj kolejną liczbę ";
		j = j + i;
		cin >> i;
	}
	cout << "Twoja suma to " << j << endl;


}	
