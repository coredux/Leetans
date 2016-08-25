#include <iostream>
#include <algorithm>

using namespace std;

// submit the codes below

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if ( triangle.size() == 0 ) {
            return 0;
        }
        vector<int> dp ( triangle[triangle.size()-1].size() , triangle[0][0] );

        for ( int i = 1 ; i < triangle.size() ; ++i ) {
            int m = triangle[i].size();
            dp[m-1] = dp[m-2] + triangle[i][m-1];
            for ( int j = m - 2; j > 0 ; --j ) {
                dp[j] = min( dp[j-1] + triangle[i][j] , dp[j] + triangle[i][j] );
            }
            dp[0] += triangle[i][0];
        }
        int ret = dp[0];
        for ( int i = 0 ; i < dp.size() ; ++i ) {
            if ( ret > dp[i]) {
                ret = dp[i];
            }
        }
        return ret;

    }
};

// submit the codes above



int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
