#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n;
long long m;
long long trees[N];

bool iws(int h){
    long long wood=0;
    for (int i = 0; i < n; i++)
    {
        if(trees[i]>=h){
            wood+=trees[i]-h;
        }
    }
    return wood >=m;
}


int main(){

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }

    int lo=0;
    int hi =1e6;
    int m;
    while (hi-lo>1)
    {
        m=(hi+lo)/2;
        if(iws(m)){
            lo=m;
        }
        else{
            hi=m-1;
        }
    }
    if(iws(hi)){
        cout << hi << endl;
    }else{
        cout << lo<<endl;
    }   
}