#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
  int x[3][3];
  int y[3][3];
  int s[3][3];
  
  for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
      cin >> x[i][j];
      }
  }
  for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
      cin >> y[i][j];
      }
  }
  
  for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
          s[i][j] = 0;
          for(int k=0; k<3; k++){
            s[i][j] += x[i][k] * y[k][j]; 
          }
            
      }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cout << s[i][j] << " ";
    }
    cout << endl;
  }

return 0;
}