class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() == 0 ) {
            return  0;
        }
        if ( nums.size() == 1 ) {
            return nums[0];
        }
        if ( nums.size() == 2 ) {
            return max( nums[0] , nums[1]);
        }

        vector<int> dp( nums.size() , 0 );
        vector<int> dpRev( nums.size() , 0 );
        dp[0] = 0;
        dp[1] = nums[1];
        for ( int i = 2 ; i < nums.size() ; ++i ) {
            dp[i] = max( dp[i-1] , dp[i-2] + nums[i] );
        }

        dpRev[nums.size()-1] = 0;
        dpRev[nums.size()-2] = nums[nums.size() - 2 ];
        for ( int i = nums.size() - 3 ; i >= 0 ; --i ) {
            dpRev[i] = max( dpRev[i+1] , dpRev[i+2] + nums[i]);
        }

        return max( dp[nums.size()-1] , dpRev[0]);
    }
};
