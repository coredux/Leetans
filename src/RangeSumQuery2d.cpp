class NumMatrix {
private:
    vector<vector<int>> _vertical; // use this
    vector<vector<int>> _horizontal;
    int _rows;
    int _cols;
public:
    NumMatrix(vector<vector<int>> &matrix): _rows(-1), _cols(-1) {
        int rows;
        int cols;
        rows = this->_rows = matrix.size();
        if ( this->_rows > 0 ) {
            cols = this->_cols = matrix[0].size();
            this->_vertical.assign( this->_rows , vector<int>( this->_cols , 0 ));
            this->_horizontal.assign( this->_rows , vector<int>( this->_cols , 0 ));

            // initial horizontal sum
            for ( int i = 0 ; i < rows ; ++i ) {
                this->_horizontal[i][0] = matrix[i][0];
            }
            for ( int i = 0 ; i < rows; ++i ) {
                for ( int j = 1; j < cols ; ++j ) {
                    this->_horizontal[i][j] = this->_horizontal[i][j-1] + matrix[i][j];
                }
            }

            // initial vertical sum
            for ( int i = 0 ; i < cols; ++i ) {
                this->_vertical[0][i] = this->_horizontal[0][i];
            }
            for ( int i = 1 ; i < rows ; ++i ) {
                for ( int j = 0 ; j < cols; ++j ) {
                    this->_vertical[i][j] = this->_vertical[i-1][j] + this->_horizontal[i][j];
                }
            }

        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        vector<int> delta( this->_cols, 0);
        // use row first
        for ( int i = 0 ; i < this->_cols; ++i ) {
            if ( row1 - 1 >= 0 ) {
                delta[i] = this->_vertical[row2][i] - this->_vertical[row1-1][i];
            } else {
                delta[i] = this->_vertical[row2][i];
            }
        }

        if ( col1 - 1 >= 0 ) {
            return delta[col2] - delta[col1-1];
        } else{
            return delta[col2];
        }

    }
};
