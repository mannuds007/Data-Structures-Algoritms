#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "abc"; //O(logn)
    m[5] = "cdc";
    m[6];
    m.insert({3, "xyz"});
    for (const auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    int x=5;
    auto it = m.find(x); //O(logn)
    if (it == m.end()) {
        cout << x << ':' <<"No Value";
        }
    else {
        cout << (*it).first << " " << (*it).second << endl;
        m.erase(it);
        }
    for (const auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    m.clear();
    for (const auto &pr : m) {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}
