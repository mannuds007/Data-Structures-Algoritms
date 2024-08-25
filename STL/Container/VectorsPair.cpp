#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> v;
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
    for (const auto &p : v) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
