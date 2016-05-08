#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int integerBreak(int n) {
        vector<int> pre(n+1,1);
        for ( int i = 2 ; i < n ; ++i ) {
            int tmpMax = 1;
            for ( int j = 1 ; j <= i/2 ; ++j ) {
                if ( tmpMax < j * pre[ i - j] ) {
                    tmpMax = j * pre[ i - j ];
                }
            }
            pre[ i ] = max( tmpMax , i );
        }
        int maxRet = 1;
        for ( int i = 1 ; i <= n / 2; ++i ) {
            if( maxRet < i * pre[ n - i ] ) {
                maxRet = i * pre[ n - i ];
            }
        }
        return maxRet;
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.integerBreak( 100 ) << endl;
    cout << sizeof(int) << sizeof(int64_t) << endl;
    return 0;
}