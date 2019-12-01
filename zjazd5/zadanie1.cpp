#include <iostream>
#include <vector>
// Badysiak Pawel
// Turek Wojtek

using namespace std;

int main()
{
    int i;
    vector<int> tab;
    while(1){
        cin >> i;
        tab.push_back(i);
        if(i==0){
            break;
        }
    }
    
    for(int i=0; i<tab.size()-1; i++)
        cout << tab[i] << " ";
    
    return 0;
    
}
