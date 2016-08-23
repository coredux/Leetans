#include <iostream>
#include <algorithm>

using namespace std;

// submit the codes below

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if ( n == 0 ) {
            return 0;
        }

        int m = grid[0].size();

        vector<vector<int>> dp( n , vector<int>(m,0));

        dp[0][0] = grid[0][0];
        for ( int i = 1; i < n ; ++i ) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for ( int i = 1 ; i < m ; ++i ) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for ( int i = 1 ; i < n ; ++i ) {
            for ( int j = 1 ; j < m ; ++j ) {
                dp[i][j] = min( dp[i-1][j] + grid[i][j] , dp[i][j-1] + grid[i][j] );
            }
        }

        return dp[n-1][m-1];
    }
};

// submit the codes above

int main() {
    vector<int> line1 { 1 , 2 , 5 };
    vector<int> line2 { 3, 2, 1};
    vector<vector<int>> in{ line1, line2 };
    Solution s;
    cout << s.minPathSum( in ) << endl;
    return 0;
}
