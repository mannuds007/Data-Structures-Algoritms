#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    // cout << str;
    // cout << str[0];
    // str[0]='a';

    // cout << str;

    string str_rev;

    int i=str.size();
    while(i>=0){
        str_rev.push_back(str[i]);
        i--;
    }

    cout << str_rev;


}