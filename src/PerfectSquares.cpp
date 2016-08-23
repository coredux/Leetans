#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
private:
    void initialDp( vector<int>& dp , int n ) {
        dp[0] = 0;
        for ( int i = 1 ; i <= n ; ++i ) {
            if ( i * i > n ) {
                break;
            }
            dp[i * i] = 1;
        }
    }
public:
    int numSquares(int n) {
        vector<int> dp( n + 1 , n );
        this->initialDp( dp , n );

        int minNum = n;
        for ( int i = 1 ; i <= n ; ++i ) {
            int innerMin = n;
            for ( int j = 0; j * j <= ( i / 2 ) ; ++j ) {
                int k = j * j;
                if ( dp[k] + dp[i-k] < innerMin ) {
                    innerMin = dp[k] + dp[i-k];
                }
            }
            dp[i] = innerMin;
            if ( minNum > innerMin ) {
                minNum = innerMin;
            }
        }
        return dp[n];
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}
