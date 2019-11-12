#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

  int i=0;
  int j=0;
  int x=1;
  string tab;
  cin>>tab;
  while (tab[i]!=0){
    i++;
  }
  while(i>0){
    if((char)(tab[j])>=65&&(char)(tab[j])<=90)
  {
  tab[j]=(char)(tab[j]+32);
  }
  if((char)(tab[i-1])>=65&&(char)(tab[i-1])<=90){
    tab[i-1]=(char)(tab[i-1]+32);
  }
  if (tab[i-1]!=tab[j])
  {
  x=0; break;
  }
  i--;
  j++;
  }
  cout<< endl << x <<endl;
  return 0;
}
