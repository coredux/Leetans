#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int numTrees(int n) {
        vector< vector<int> > dp = vector< vector<int> >( static_cast<unsigned int>( n + 1 ) , vector<int>(
                static_cast<unsigned int>( n + 1 ) , 1 ) );
        for ( int i = n ; i > 0 ; --i ) {
            for ( int j = i + 1 ; j <= n ; ++j ) {
                int sum = 0;
                for ( int k = i ; k <= j ; ++k ) {
                    int left = ( k - 1 >= i ? dp[ i ][ k - 1 ] : 1 );
                    int right = ( k + 1 <= j ? dp[ k + 1 ][ j ] : 1 );
                    sum += left * right;
                }
                dp[ i ][ j ] = sum;
            }
        }
        return dp[ 1 ][ n ];
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.numTrees( 5 )<< endl;
    return 0;
}