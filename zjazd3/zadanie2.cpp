#include <iostream>
using namespace std;

int main(){

  float x[25];
  float k = 0;
  float s1 = 0;
  float s2 = 0;
  float s3 = 0;
  float s4 = 0;
  float s5 = 0;

  for(int i=0; i<=4; i++){
  cin >> x[i];
  s1 = s1 + x[i];
  k = k + x[i];
 }
 for(int i=5; i<=9; i++){
  cin >> x[i];
  s2 = s2 + x[i];
  k = k + x[i];
 }
 for(int i=10; i<=14; i++){
  cin >> x[i];
  s3 = s3 + x[i];
  k = k + x[i];
 }
 for(int i=15; i<=19; i++){
  cin >> x[i];
  s4 = s4 + x[i];
  k = k + x[i];
 }
 for(int i=20; i<=24; i++){
  cin >> x[i];
  s5 = s5 + x[i];
  k = k + x[i];
 }

  cout << k/25 << endl;
  s1 = s1/5;
  s2 = s2/5;
  s3 = s3/5;
  s4 = s4/5;
  s5 = s5/5;

  if(s1 > k/25)
    cout << s1 << endl;
  if(s2 > k/25)
    cout << s2 << endl;
  if(s3 > k/25)
    cout << s3 << endl;
  if(s4 > k/25)
    cout << s4 << endl;
  if(s5 > k/25)
    cout << s5 << endl;
  return 0;
}
