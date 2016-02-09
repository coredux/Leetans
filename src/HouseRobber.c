//
// Created by seanr on 2016/2/9.
//

#include <stdlib.h>

// submit the codes below

int maxOfTwo( int a , int b ) {
    return a>b?a:b;
}

int rob(int* nums, int numsSize) {

    if( numsSize == 0 ) {
        return 0;
    }
    if( numsSize == 1 ) {
        return *nums;
    }
    if( numsSize == 2 ) {
        return maxOfTwo( *nums , *( nums + 1 ) );
    }

    int* dp = calloc( (size_t)( numsSize ) , sizeof(int) );
    // init
    *dp = *nums;
    *( dp + 1 ) = maxOfTwo( *nums , *( nums + 1 ) );

    for( int i = 2 ; i < numsSize ; i++ ) {
        *( dp + i ) = maxOfTwo( dp[ i - 2 ] + *( nums + i ) , dp[ i - 1 ] );
    }
    int ret = *( dp + numsSize - 1 );
	free( dp );
	return ret;
}

// submit the codes above

int main() {
    return 0;
}

