//
// Created by seanr on 2016/2/21.
//

#include <stdlib.h>

// submit the codes below

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    if( nums == NULL || numsSize == 0 ) {
        return NULL;
    }

    int* ret = calloc( (size_t)numsSize , sizeof(int) );
    *returnSize = numsSize;

    *ret = 1;
    for( int i = 1 ; i < numsSize ; i++ ) {
        *( ret + i ) = *( nums + i - 1 ) * *( ret + i - 1 );
    }

    int tmp = 1;
    for( int i = numsSize - 1 ; i > -1 ; i-- ) {
        *( ret + i ) *= tmp;
        tmp *= *( nums + i );
    }

    return ret;

}

// submit the codes above

int main()  {
    int data[] = { 0 , 0 };
    int sz = 0;
    int* ret = productExceptSelf( data , 2 , &sz );
    return 0;
}


