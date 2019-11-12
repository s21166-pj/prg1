#include <iostream>
#include <cstdlib>

using namespace std;
int main(){
  int i=0;
  int j=0;
  int tab[9];
  for(;i<9;i++){
    cin>>tab[i];
  }
  while (j<9)
  {
  cout<<tab[j]<<" "<<tab[j+1]<<" "<<tab[j+2]<<endl;
  j=j+3;
  }

return 0;
}
