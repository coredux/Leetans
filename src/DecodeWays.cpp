#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int numDecodings(string s) {
        if ( s.length() == 0 ) {
            return 0;
        }
        vector<int> dp( s.length() + 1 , 1 );
        const char * pch = s.c_str();
        if ( *pch == '0' ) {
            dp[1] = 0;
        }
        for ( int i = 1 ; i < s.length() ; ++i ) {
            char now = *( pch + i );
            char pre = *(pch + i - 1 );
            int dpIdx = i + 1;
            if ( now == '0') {
                if ( pre > '0' && pre < '3' ) {
                    dp[dpIdx] = dp[dpIdx-2];
                } else {
                    dp[dpIdx] = 0;
                }
            } else {
                int x = ( pre - '0' ) * 10 + ( now - '0' );
                if ( x > 10 && x < 27 ) {
                    dp[dpIdx] = dp[dpIdx-1] + dp[dpIdx-2];
                } else {
                    dp[dpIdx] = dp[dpIdx-1];
                }
            }
        }
        return dp[s.length()];
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.numDecodings("17") << endl;
    return 0;
}
