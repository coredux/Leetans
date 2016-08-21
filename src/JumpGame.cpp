#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    bool canJump(vector<int>& nums) {

        if ( nums.size() < 1 ) {
            return false;
        }

        int farest = 0;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            if ( i <= farest ) {
                int step = nums[i];
                if ( i + step > farest ) {
                    farest = i + step;
                }
            }
        }
        return nums.size() - 1 <= farest;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}