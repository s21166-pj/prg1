#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  int x[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  int i,j,k,l=0;

  while(l < 10){
    cin >> k;
    i = (k-1)/3;
    j = (k-1)%3;
    if(x[i][j]){
        break;
    }

    if(l%2 == 0){
        x[i][j] = 1;
    }else{
        x[i][j] = 2;
    }

    l++;
  }


  /* for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << x[i][j] << " ";
    }
    cout << endl;
  }*/
cout << 0;
return 0;
}
