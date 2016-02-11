//
// Created by seanr on 2016/2/11.
//

#include <stdlib.h>

// submit the codes below

int* getRow(int rowIndex, int* returnSize) {

    *returnSize = rowIndex + 1;
    if( rowIndex < 0 ) {
        return NULL;
    }
    int* ret = calloc( (size_t)( rowIndex + 1 ) , sizeof(int) );
    for( int i = 0 ; i < rowIndex + 1 ; i++ ) {
        for( int j = i ; j >= 0 ; j-- ) {
            if( j == 0 || j == i ) {
                *( ret + j ) = 1;
            } else {
                *( ret + j ) += *( ret + j - 1 );
            }
        }
    }
    return ret;


}

// submit the codes above

int main() {

    return 0;
}

