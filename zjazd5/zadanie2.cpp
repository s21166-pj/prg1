#include <iostream>
#include <vector>

// Badysiak Pawel
// Turek Wojciech

using namespace std;

int main()
{

    int i;
    int s = 0;
    vector<int> tab;
    while(1){
        cin >> i;
        tab.push_back(i);
        if(l==0){
            break;
        }
    }
    
    for(int i=0; i<tab.size()-1; i++){
        s += tab[i];
    }
    
    cout << s / (tab.size()-1) << endl;
    
    
    return 0;
}
