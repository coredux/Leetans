#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {

public:
    vector<int> countBits(int num) {
        vector<int> table( num + 1 , 0 );
        for( int i = 1 ; i <= num ; ++i ) {
            if( ( i - 1 )  & 1 ) {
                table[ i ] = table[ i & ( i - 1 ) ] + 1;
            } else {
                table[ i ] = table[ i - 1 ] + 1;
            }
        }
        return table;
    }

};

// submit the codes above

int main() {
    Solution s;
    vector<int> v = s.countBits( 5 );
    for( auto i = v.begin() ; i != v.end() ; ++i ) {
        cout << *i << endl;
    }
    return 0;
}