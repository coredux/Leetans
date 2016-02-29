#include <iostream>
#include <cmath>

using namespace std;

// submit the codes below

class Solution {
public:
    int bulbSwitch(int n) {
        return int( sqrt(n) );
    }
};

// submit the codes above

int main() {
    Solution s;
    cout<< s.bulbSwitch( 4 ) << endl;
    return 0;
}