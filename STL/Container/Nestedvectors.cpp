#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        vector<int> temp(n);
        for (int j = 0; j < n; ++j) {
            cin >> temp[j];
        }
        v.push_back(temp);
    }
    // Example of accessing elements
    for (const auto& row : v) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
