#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if ( nums.size() < 1 ) {
            return 0;
        }

        vector<int> dp( nums.size() , 1 );

        for ( int i = 0; i < nums.size(); ++i ) {
            for ( int j = 0; j < i ; ++j ) {
                if ( nums[j] < nums[i] && dp[j] + 1 > dp[i] ) {
                    dp[i] = dp[j] + 1;
                }
            }
        }

        int ret= dp[0];
        for ( int i = 1 ; i < nums.size() ; ++i ) {
            if ( ret < dp[i] ){
                ret = dp[i];
            }
        }

        return ret;

    }
};

// submit the codes above

int main() {
    Solution s;
    vector<int> in {1,3,6,7,9,4,10,5,6};
    cout << s.lengthOfLIS(in) << endl;
    return 0;
}