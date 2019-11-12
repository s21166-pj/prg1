#include <iostream>
using namespace std;

int main() {

  cout << "Hello World" << endl;

  int x[10];
 
  for(int i=0; i<=10; i++){
  cout << "Podaj liczbe " << endl; 
  cin >> x[i];
   }

  for(int k=9; k>=0; k--){
  cout << x[k] << endl;
}

  return 0;

}
