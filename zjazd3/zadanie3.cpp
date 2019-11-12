#include <iostream>
using namespace std;

int main(){

  string x;
  cin >> x;
  int l = 0;
  while(x[l]!=0) {

  l = l + 1;

  }
  for (l=l; l>=0; l--){

    cout << x[l];
  }

  return 0;
}
