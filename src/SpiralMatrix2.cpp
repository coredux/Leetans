#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ret( n , vector<int>( n , 0 ) );

        int left = 0;
        int right = n;
        int top = 0;
        int bottom = n;
        int idx = 0;

        while( left < right && top < bottom ) {

            for ( int i = left ; i < right ; ++i ) {
                ret[top][i] = ++idx;
            }
            ++top;
            if ( top >= bottom ) {
                break;
            }

            for ( int i = top ; i < bottom ; ++i ) {
                ret[i][right - 1] = ++idx;
            }
            --right;
            if ( left >= right ) {
                break;
            }

            for ( int i = right - 1 ; i >= left ; --i ) {
                ret[bottom - 1][i] = ++idx;
            }
            --bottom;
            if ( top >= bottom ) {
                break;
            }

            for ( int i = bottom - 1; i >= top; --i ) {
                ret[i][left] = ++idx;
            }
            ++left;

        }

        return ret;

    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}