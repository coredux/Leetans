class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp( n + 1 , vector<int>( n + 1 , 0 ) );
        for ( int i = 2 ; i <= n ; ++i ) {
            for ( int j = i - 1 ; j >= 1; --j ) {
                int innerRet = INT32_MAX;
                if ( j + 1 < i ) {
                    for ( int k = j + 1; k < i ; ++k ) {
                        innerRet = min( innerRet , max( dp[j][k-1] , dp[k+1][i] ) + k );
                    }
                } else {
                    innerRet = j;
                }
                dp[j][i] = innerRet;
            }
        }
        return dp[1][n];
    }
};
