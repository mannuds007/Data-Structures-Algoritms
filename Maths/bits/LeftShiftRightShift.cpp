#include <iostream>
using namespace std;

int main() {
    int n = 4; // 0100
    int left_shift = n << 1;  // 1000 (8), equivalent to n * 2
    int right_shift = n >> 1; // 0010 (2), equivalent to n / 2
    cout << "Left Shift: " << left_shift << "\n";
    cout << "Right Shift: " << right_shift << "\n";
    int result = 1 << n; // 8 (2^3)
    cout << "1 << " << n << " = " << result << "\n";
    return 0;
}
