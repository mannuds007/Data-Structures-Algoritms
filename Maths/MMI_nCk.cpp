/// There are N children and k tofees, K<N
// counnt the number of ways to distribute tofee
// among N students, such that each students get 1 tofee onlynCk
// N< 10^9, K<N<10^9



#include<bits/stdc++.h>
using namespace std;

int binexp(int a, int b , int m){
    int result =1;
    while (b>0)
    {
        if(b&1){
            result = (result*1LL*a)%m;
        }
        a = (a*1LL*a)%m;
        b>>=1;
    }
    return result;
    


}


const int N = 1e6+10;
int fact[N];
const int M = 10^9+7;
int main(){
fact[0]=1;
for (int i = 0; i < N; i++)
{
    fact[i] = (fact[i-1]*1LL*i)%M;
}
int n, k;
cin >> n >> k;

int ans = fact[n];
int den = (fact[n-k]*1LL*fact[k])%M;
ans = ans* binexp(den, M-2, M);

cout << ans << endl;

}