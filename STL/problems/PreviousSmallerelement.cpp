#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> G(A.size());
    stack<int> s;
    for(int i=0; i<A.size(); i++){
        if(s.empty()){
            s.push(A[i]);
            G[i]=-1;
        }
        else{
            if(s.top()<A[i]){
                G[i]=s.top();
                s.push(A[i]);
            }
            else{
                s.pop();
                while(!s.empty()){
                    if(s.top()<A[i]){
                        G[i]=s.top();
                        s.push(A[i]);
                        break;
                    }
                    s.pop();
                }
                if(s.empty()){
                    G[i]=-1;
                    s.push(A[i]);
                }
            }
        }
    }
    return G;
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];    
    }
    vector<int> G=prevSmaller(a);
    for (int i = 0; i < n; i++)
    {
        cout << G[i] <<" ";    
    }
    
    
}