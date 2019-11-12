#include <iostream>
using namespace std;
// Badysiak Paweł
// Wadas Michał

int main(){
	int i, j;
	cin >>i;
	do {
		cin >>j;
	if(j > i){
	cout << "Za wysoko, try again" << endl;
	}else{
	cout << "za malo" << endl;
	}
	}while( i != j);
	cout << "Brawo wygrales";
	return 0;
}
