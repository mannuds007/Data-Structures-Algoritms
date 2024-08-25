#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, string> p;
    p = make_pair(1, "example");
    cout << p.first << " " << p.second << endl;

}
