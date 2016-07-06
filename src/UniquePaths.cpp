#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(static_cast<unsigned int>(m) ,
                                 vector<int>(static_cast<unsigned int>(n) , 0 ) );
        this->rowNum = m;
        this->colNum = n;
        grid[0][0] = 1;
        for ( int i = 0 ; i < m ; ++i ) {
            for ( int j = 0 ; j < n ; ++j ) {
                if ( i != 0 || j != 0 ) {
                    grid[i][j] =
                            retrieve(grid, i - 1, j) +
                            retrieve(grid, i, j - 1);
                }
            }
        }
        return grid[m-1][n-1];

    }

private:
    int rowNum = -1;
    int colNum = -1;
    int retrieve( vector<vector<int>>&container , int x , int y ) {
        if ( x >= 0 && x < this->rowNum && y >= 0 && y < this->colNum ) {
            return container[x][y];
        } else {
            return 0;
        }
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.uniquePaths( 3, 7 ) << endl;
    return 0;
}