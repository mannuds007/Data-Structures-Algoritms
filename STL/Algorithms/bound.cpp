#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 2, 3, 4, 5}; // sorting is required
    auto it = lower_bound(v.begin(), v.end(), 2); // First position of 2
    cout << "Lower bound of 2: " << *it << endl;// sets.lower_bound(number)
    it = upper_bound(v.begin(), v.end(), 3); // First position greater than 2
    cout << "Upper bound of 3: " << *it << endl; // sets.upper_bound(number)
    return 0;
}
