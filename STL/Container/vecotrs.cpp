#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> v;
    int x;
    cin >> x;
    v.push_back(x); // Adds value to the end
    v.pop_back(); // Removes the last element
    cout << "Size: " << v.size() << endl; // Returns the number of elements
    v[0]; // Accesses the first element
    vector<int> v2(10); // Initializes vector with 10 elements
    v2 = v; // Copies vector v into v2
    return 0;
}
