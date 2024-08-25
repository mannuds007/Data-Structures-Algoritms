#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    for (int value :v) {
        cout << value << " ";
    }
    cout << endl;
    for (int &value :v) {
        value++;
        cout << value << " ";
    }
    auto a = 1;
    cout << endl << a << endl;
    vector<pair<int,int>> vp = {{1,2},{2,3}};

    for(auto &value: vp){
        cout << value.first << " " << value.second << " ";
    }
    return 0;
}