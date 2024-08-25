#include <iostream>
#include <set>
using namespace std;

void print(set<string> &s){
    for (const auto &val : s) {
        cout << val << endl;
    }
}
void print_int(set<int> &s){
    for (const auto &val : s) {
        cout << val << endl;
    }
}

int main() {
    set<string> s;
    set<int> i;
    s.insert("abc"); // unique values of type
    s.insert("def");
    i.insert(2); // unique values of type
    i.insert(1);
    i.insert(1);
    print(s);
    print_int(i);
    cout << "//" << endl;
    auto it = s.find("a");
    if (it != s.end()) {
        cout << *it;
        s.erase(it);
        cout << endl;
    }
    print(s);
    return 0;
}
