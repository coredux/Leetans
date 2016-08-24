#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        if ( n == 0 ) {
            return 0;
        }
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp( n , vector<int>(m,0));

        if ( obstacleGrid[0][0] == 0 ) {
            dp[0][0] = 1;
        }

        for ( int i = 1 ; i < m ; ++i ) {
            if ( obstacleGrid[0][i] ) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }

        for ( int i = 1; i < n ; ++i ) {
            if ( obstacleGrid[i][0] ) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }

        for ( int i = 1; i < n ; ++i ){
            for ( int j = 1; j < m; ++j ) {
                if ( obstacleGrid[i][j] ){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};

// submit the codes above

int main() {
    vector<int> a { 0 , 0 , 0 };
    vector<int> b { 1 , 1 , 0 };
    vector<int> c { 0 , 0 , 0 };
    vector<vector<int>> in{a,b,c};
    Solution s;
    cout << s.uniquePathsWithObstacles(in) << endl;
    return 0;
}
