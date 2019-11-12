#include <iostream>
using namespace std;

int main() {

  string napis;
  cin >> napis;
  char x;
  for(int i=0; napis[i] !=0; i++){
  x = napis[i];
  x = tolower(x);
  napis[i] = x;
  }

  cout << napis;

  return 0;
}
