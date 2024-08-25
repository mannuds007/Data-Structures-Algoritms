#include<bits/stdc++.h>
using namespace std;

void func(int a[], int b[][2]){
    b[0][0]=3;
    a[0]=1;
}
int main(){
    int a[10] ,b[10][2];
    a[0]=7;
    b[0][0]=8;

    func(a,b);
    cout << a[0] <<" "<< b[0][0] << endl;

}