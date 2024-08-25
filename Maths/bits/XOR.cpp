#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 9;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout << "After swap, x: " << x << ", y: " << y << "\n";
    return 0;
}
