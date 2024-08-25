#include <iostream>
using namespace std;

long long binExp(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long res = binExp(a, b / 2, mod);
    res = (res * res) % mod;
    if (b % 2==1) res = (res * a) % mod;
    return res; 
}

int main() {
    long long a = 2, b = 10, mod = 1e9+7;
    cout << "Result: " << binExp(a, b, mod) << "\n";
    return 0;
}
