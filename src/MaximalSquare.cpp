class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if ( rows == 0 ) {
            return 0;
        }
        int cols = matrix[0].size();

        vector<vector<int>> dp( rows , vector<int>( cols , 0 ) );

        int maxEdgeLen = 0;
        for ( int i = 0; i < rows ; ++i ) {
            if ( matrix[i][0] == '1' || matrix[i][0] == 1 ) {
                dp[i][0] = 1;
                maxEdgeLen = 1;
            }
        }
        for ( int i = 0 ; i < cols; ++i ) {
            if (matrix[0][i] == '1' || matrix[0][i] == 1 ) {
                dp[0][i] = 1;
                maxEdgeLen = 1;
            }
        }

        for ( int i = 1 ; i < rows; ++i ) {
            for ( int j = 1; j < cols; ++j ) {
                if ( matrix[i][j] == '1' || matrix[i][j] == 1 ) {
                    dp[i][j] = min( dp[i-1][j] , min( dp[i-1][j-1] , dp[i][j-1] )  ) + 1;
                    if ( dp[i][j] > maxEdgeLen ) {
                        maxEdgeLen = dp[i][j];
                    }
                }
            }
        }
        return maxEdgeLen * maxEdgeLen ;
    }
};
