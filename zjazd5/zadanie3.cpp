#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <bits/stdc++.h> 

//Badysiak Pawel
//Turek Wojciech
using namespace std;

int
main ()
{
  vector < string > tab;
  vector < string > pub;
  int x;
  string class_name;
  string player_name;
  unsigned seed = 0; 
  cin >> x;

  for (int i = 0; i < x; i++)
    {
      cin >> class_name;
      tab.push_back (class_name);
    }
  for (int i = 0; i < x; i++)
    {
      cin >> player_name;
      pub.push_back (player_name);
    }
    shuffle(tab.begin(), tab.end(), default_random_engine(seed));
  for (int i = 0; i < x; i++)
    {
            cout << pub[i] <<"-"<< tab[i] << endl;
    }

  return 0;
}
