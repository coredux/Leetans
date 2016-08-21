#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        if ( matrix.size() < 1 || matrix[0].size() < 1 ) {
            return ret;
        }

        int right = matrix[0].size();
        int bottom = matrix.size();
        int left = 0;
        int top = 0;

        while ( left < right && top < bottom ) {

            for (int i = left; i < right; ++i) {
                ret.push_back(matrix[top][i]);
            }
            ++top;
            if ( top >= bottom ) {
                break;
            }

            for ( int i = top ; i < bottom ; ++i ) {
                ret.push_back(matrix[i][right-1]);
            }
            --right;
            if ( left >= right ) {
                break;
            }

            for ( int i = right - 1 ; i >= left ; --i ) {
                ret.push_back(matrix[bottom-1][i]);
            }
            --bottom;
            if ( top >= bottom ) {
                break;
            }

            for ( int i = bottom - 1; i >= top ; --i ) {
                ret.push_back(matrix[i][left]);
            }
            ++left;

        }

        return ret;
    }
};

// submit the codes above

int main() {
    vector<vector<int>> a( 4 , vector<int>( 2 , 0 ) );
    int cnt = 1;
    for ( int i = 0 ; i < 4 ; ++i ) {
        for ( int j = 0 ; j < 2 ; ++j ) {
            a[i][j] = cnt++;
        }
    }
    Solution s;
    vector<int> b = s.spiralOrder(a);
    for ( int i = 0 ; i < b.size(); ++i ) {
        cout << b[i] << endl;
    }
    return 0;
}