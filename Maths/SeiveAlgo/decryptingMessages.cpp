#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 5;
vector<bool> is_prime(mx + 1, true);
vector<int> highest_prime(mx + 1, 0);
vector<bool> can_remove(mx + 1);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= mx; ++i) {
        if (is_prime[i]) {
            highest_prime[i] = i;
            for (long long j = (long long)i * i; j <= mx; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    highest_prime[j] = i;
                }
            }
        }
    }
}

vector<int> prime_factors(int n) {
    vector<int> pf;
    while (n > 1) {
        int prime_factor = highest_prime[n];
        while (n % prime_factor == 0)
            n /= prime_factor;
        pf.push_back(prime_factor);
    }
    return pf;
}

int main() {
        sieve();

    int n, q, x;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        can_remove[a[i]] = true;
    }
    for (int i = 2; i <= mx; ++i) {
        if (can_remove[i]) {
            for (long long j = i; j <= mx; j *= i) {
                can_remove[j] = true;
            }
        }
    }

    while (q--) {
        cin >> x;
        vector<int> pf = prime_factors(x);
        int len = pf.size();
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                int product = pf[i] * pf[j];
                if (i == j && x % product != 0)
                    continue;
                int left = x / product;
                if (can_remove[left] || left == 1) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}
