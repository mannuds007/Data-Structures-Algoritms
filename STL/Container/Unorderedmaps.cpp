#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m; 
    m[1] = 2;//O(1)
    m[3] = 4;
    m[2] = 5;
    m[1]=4;
    for (const auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}
