#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end()); // Sorts the vector
    cout << "Min element: " << *min_element(v.begin(), v.end()) << endl;
    cout << "Max element: " << *max_element(v.begin(), v.end()) << endl;
    cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << endl;
    cout << "Count of 3: " << count(v.begin(), v.end(), 3) << endl;
    auto it = find(v.begin(), v.end(), 4);
    if (it != v.end()) {
        cout << "Element 4 found at index: " << distance(v.begin(), it) << endl;
    }
    reverse(v.begin(), v.end()); // Reverses the vector
    for (const auto &val : v) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
