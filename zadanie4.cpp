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
    
    if(x[0][0] == 1 && x[1][0] == 1 && x[2][0] == 1 ){
        cout << x[0][0];
        break;
    }
    if(x[0][1] && x[1][1] && x[2][1] == 1 ){
        cout << x[0][1];
        break;
    }
    if(x[0][2] && x[1][2] && x[2][2] == 1 || 2){
        cout << x[0][2];
        break;
    }
    if(x[0][0] && x[0][1] && x[0][2] == 1 || 2){
        cout << x[0][0];
        break;
    }
    if(x[1][0] && x[1][1] && x[1][2] == 1 || 2){
        cout << x[1][0];
        break;
    }
    if(x[2][0] && x[2][1] && x[2][2] == 1 || 2){
        cout << x[2][0];
        break;
    }
    if(x[0][0] && x[1][1] && x[2][2] == 1 || 2){
        cout << x[0][0];
        break;
    }
    if(x[0][2] && x[1][1] && x[2][0] == 1 || 2){
        cout << x[0][2];
        break;
    }
    l++;
  }
  
  
   for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << x[i][j] << " ";
    }
    cout << endl;
  }
  
return 0;
}