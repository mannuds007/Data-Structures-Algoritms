#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int a;
    cin >> a;
    int lo=0;
    int hi =n-1;
    int m;
    while (hi-lo>1)
    {
        m=(hi+lo)/2;
        if(v[m]<a){
            lo=m+1;
        }
        else{
            hi=m;
        }
    }
    if(v[lo]==a){
        cout << lo << endl;
    }else if(v[hi]==a){
        cout << hi << endl;
    }else{
        cout << "Not Found";
    }   
}