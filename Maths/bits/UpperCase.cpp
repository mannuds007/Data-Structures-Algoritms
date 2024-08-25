#include <iostream>
using namespace std;

int main() {
    char lower = 'c'; // 0110 0011
    char upper = 'C'; // 0100 0011
    lower = lower & '_'; // 0100 0011 ('C')
    upper = upper | ' '; // 0110 0011 ('c')
    cout << "Lower to Upper: " << lower << "\n";
    cout << "Upper to Lower: " << upper << "\n";
    return 0;
}
