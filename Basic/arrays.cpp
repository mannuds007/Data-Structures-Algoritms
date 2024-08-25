#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10]; // a[10e5] size
    int n;
    cin >> n;
    for(int i=0;  i<n; i++ ){
        cin >> a[i];
    }
    cout <<a[1]+a[n-1];
}