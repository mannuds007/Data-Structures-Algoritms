#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    map<int, multiset<string>> mp;
    while (n--)
    {
      
        string name;
        int m;
        cin >> name >> m;
        mp[m].insert(name);
    }

    for (auto pr = mp.rbegin(); pr != mp.rend(); ++pr){
        for (auto &val : (*pr).second) {
        cout <<val<< " " <<(*pr).first<< endl;
    }   
    }

    
}