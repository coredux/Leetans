#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sumbit the codes below

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        if ( nums.size() == 0 ) {
            return 0;
        }

        vector<int> dpPos( nums.size() , 0 );
        vector<int> dpNeg( nums.size() , 0 );
        int maxProduct = dpPos[0] = dpNeg[0] = nums[0];

        for ( int i = 1 ; i < nums.size() ; ++i ) {
            dpPos[i] = max( max( dpPos[i-1] * nums[i], dpNeg[i-1] * nums[i] ) , nums[i] );
            dpNeg[i] = min( min( dpPos[i-1] * nums[i], dpNeg[i-1] * nums[i] ) , nums[i] );
            if ( dpPos[i] > maxProduct ) {
                maxProduct = dpPos[i];
            }
        }
        return maxProduct;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}