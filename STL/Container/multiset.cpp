#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    for (const auto &val : ms) {
        cout << val << " ";
    }
    cout << endl;
    ms.erase(ms.find(1)); // Erases one instance of 1 because of iterator
    for (const auto &val : ms) {
        cout << val << " ";
    }
    cout << endl;
    ms.erase(2); // Erases all instances of 2
    return 0;
}
