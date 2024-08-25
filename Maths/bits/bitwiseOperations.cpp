#include <iostream>
using namespace std;

// Count Set Bit
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}


int main() {
    int a = 5, b = 3; // a = 0101, b = 0011
    int and_result = a & b; // 0001 (1)
    int or_result = a | b;  // 0111 (7)
    int xor_result = a ^ b; // 0110 (6)
    cout << "AND: " << and_result << "\n";
    cout << "OR: " << or_result << "\n";
    cout << "XOR: " << xor_result << "\n";

    //Set a Bit
    int pos = 1;
    a |= (1 << pos); // 0111 (7)
    cout << "Set bit: " << a << "\n";
    
    // Unset a bit
    int d = 7; // 0111
    d &= ~(1 << pos); // 0101 (5)
    cout << "Unset bit: " << b << "\n";
    
    //Toggle a bit
    int c = 5; // 0101
    c ^= (1 << pos); // 0100 (4)
    cout << "Toggle bit: " << c << "\n";

    // count Set BIt
    cout << "Set bits count: " << countSetBits(29) << "\n";
    
    
    //

    bool isOdd = a & 1; // true if n is odd
    cout << a << " is " << (isOdd ? "odd" : "even") << "\n";

    // Check if power of 2
    int n = 16;
    cout << n << ((n && !(n & (n - 1))) ? " is " : " is not ") << "a power of 2\n";
}
