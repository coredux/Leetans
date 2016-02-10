//
// Created by seanr on 2016/2/10.
//

#include <stdlib.h>

// submit the codes below

int** generate(int numRows, int** columnSizes, int* returnSize) {

    *columnSizes = calloc( (size_t ) numRows , sizeof(int) );
    *returnSize = numRows;
    int **ret = calloc( (size_t) numRows , sizeof(int*) );

    for( int i = 0 ; i < numRows ; i++ ) {
        int nowSize = i + 1;
        *( *columnSizes + i ) = nowSize;
        *( ret + i ) = calloc( (size_t) nowSize , sizeof(int) );

        int *nowCol = *( ret + i );
        int *preCol = NULL;
        if( i > 0 ) {
            preCol = *( ret + i - 1);
        }
        for( int j = 0 ; j < nowSize ; j++ ) {
            if( j == 0 || j == nowSize - 1 ) {
                *( nowCol + j ) = 1;
            }
            if( preCol != NULL && j > 0 && j < ( nowSize - 1 ) ) {
                *( nowCol + j ) = *( preCol + j - 1 ) + *( preCol + j );
            }
        }
    }
    return ret;

}

// submit the codes above

int main() {
    return 0;
}

