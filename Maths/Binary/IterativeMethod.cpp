#include <iostream>
using namespace std;

long long binExpIter(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a = 2, b = 10, mod = 1e9+7;
    cout << "Result: " << binExpIter(a, b, mod) << "\n";
    return 0;
}
