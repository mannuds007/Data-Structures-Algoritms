#include<bits/stdc++.h>
using namespace std;


//Reading Input and Counting Frequencies:
//The code reads n numbers and keeps a frequency count in the hsh array.
// Calculating Multiples Counts:
// The multiples_ct array is used to store the count of multiples for each number up to N.
/// Processing Queries:
// For each query, it calculates the number of multiples of p and q, and then adjusts for the LCM of p and q.



const int N = 2e5 + 10;
int hsh[N];
int multiples_ct[N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            multiples_ct[i] += hsh[j];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int p, q;
        cin >> p >> q;
        long long lcm = p * 1LL * q / __gcd(p, q);
        long ans = multiples_ct[p] + multiples_ct[q];
        if (lcm < N) {
            ans -= multiples_ct[lcm];
        }
        cout << ans << endl;
    }
    return 0;
}