#include <iostream>
using namespace std;

int main() {

  float x[5];
  float z = 0.0;
  for(int i=0; i<=4; i++){

  cin >> x[i];
  z = z + x[i];
  }
  cout << z/5;
  return 0;
}
