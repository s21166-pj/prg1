#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
  int i=0;
  int j=0;
  int k=0;
  int l=0;
  int x[9];
  int y[9];
  int s[9];
  
  for(;i<9;i++){
    cin>>x[i];
  }
  for(;k<9;k++){
    cin>>y[k];
  }
  for(;l<9; l++){
      s[l] = x[l]+y[l];
  }
  while (j<9)
  {
  cout<<s[j]<<" "<<s[j+1]<<" "<<s[j+2]<<endl;
  j=j+3;
  }

return 0;
}