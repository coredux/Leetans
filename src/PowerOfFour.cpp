#include <iostream>

using namespace std;

// submit the codes below

class Solution {
public:
    bool isPowerOfFour(int num) {
        if ( num < 0 ) {
            return false;
        }
        if ( ( num & -num ) == num && ( num & 0x55555555 ) ) {
            return true;
        }
        return false;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}