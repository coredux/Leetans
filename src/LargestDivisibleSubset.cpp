class Solution {
public:
    bool myCmp(int,int);

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ret;
        if ( nums.size() == 0 ) {
            return ret;
        }
        vector<int> dp( nums.size() + 1 , 1 );
        vector<int> back( nums.size() , -1 );
        sort( nums.begin(), nums.end() );
        dp[0] = 1;
        int maxSubNum = 0;
        int maxSubIdx = 0;
        for ( int i = 1 ; i < nums.size() ; ++i ) {
            for ( int j = 0 ; j < i ; ++j ) {
                if ( nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1 ) {
                    dp[i] = dp[j] + 1;
                    back[i] = j;
                }
            }
            if ( dp[i] > maxSubNum ) {
                maxSubNum = dp[i];
                maxSubIdx = i;
            }
        }
        while( maxSubIdx != -1 ) {
            ret.push_back(nums[maxSubIdx]);
            maxSubIdx = back[maxSubIdx];
        }
        return ret;
    }
};
