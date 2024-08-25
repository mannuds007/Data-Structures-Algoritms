#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    auto sum = [](int x, int y) { return x + y; };
    cout << "Sum: " << sum(2, 3) << endl;

    vector<int> v = {1, 2, 3, 4, 5};
    int total = 0;
    for_each(v.begin(), v.end(),
    [&total](int x) { total += x; }); // for each element
    cout << "Total sum: " << total << endl;
    
    
    int t= all_of(v.begin(), v.end(),
    [](int x) { return x>0; });
    cout << t <<endl;


    int a= any_of(v.begin(), v.end(),
    [](int x) { return x>0; });
    cout << a << endl;

    int n= none_of(v.begin(), v.end(),
    [](int x) { return x<0; });
    cout << n << endl;

    return 0;
}
