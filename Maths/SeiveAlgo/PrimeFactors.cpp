#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> sieve(int n) {
    vector<int> spf(n + 1); // smallest prime factor
    iota(spf.begin(), spf.end(), 0); // initialize spf with itself

    for (int i = 2; i * i <= n; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

vector<int> getPrimeFactors(int x, vector<int>& spf) {
    vector<int> factors;
    while (x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

int main() {
    int n = 100;
    vector<int> spf = sieve(n);
    int x = 84;
    vector<int> factors = getPrimeFactors(x, spf);
    cout << "Prime factors of " << x << ": ";
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << "\n";
    return 0;
}
