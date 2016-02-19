//
// Created by seanr on 2016/2/18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// submit the codes below


void rotate(int* nums, int numsSize, int k) {

    if( k == 0 ) {
        return ;
    }
    if( k > numsSize ) {
        k = k % numsSize;
    }

    int* tmp = calloc( (size_t)( 2 * numsSize ) , sizeof(int) );
    memcpy( tmp , nums , sizeof(int) * numsSize );
    memcpy( tmp + numsSize , nums , sizeof(int) * numsSize  );
    int start = numsSize - k;
    int end = start + numsSize;
    int numIndex = 0;
    for( int i = start ; i < end ; i++ ) {
        *( nums + numIndex ) = *( tmp + i );
        numIndex++;
    }
    free( tmp );
    return ;

}

// submit the codse above

int main() {
    int data[] = { 1 , 2  };
    rotate( data , 2 , 1 );
    return 0;
}
