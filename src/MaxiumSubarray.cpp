#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.size() < 1 ) {
            return 0;
        }

        vector<int> dp( nums.size() , 0 );
        int maxSum = nums[0];
        dp[0] = nums[0];
        for ( int i = 1; i < nums.size(); ++i ) {
            dp[i] = max( dp[i-1] + nums[i] , nums[i] );
            if ( dp[i] > maxSum ) {
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}