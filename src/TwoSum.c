//
// Created by seanr on 2016/2/21.
//

#include <stdlib.h>
#include <stdbool.h>

// submit the codes below

int* twoSum(int* nums, int numsSize, int target) {

    if( nums == NULL || numsSize == 0 ) {
        return NULL;
    }

    int a = 0 , b = 0;
    bool isFound = false;

    for( int i = 0 ; i < numsSize ; i++ ) {
        int x = *( nums + i );
        for( int j = i + 1 ; j < numsSize ; j++ ) {
            int y = *( nums + j );
            if(  x + y == target ) {
                a = i;
                b = j;
                isFound = true;
                break;
            }
        }
        if( isFound ) {
            break;
        }
    }

    int* ret = calloc( 2 , sizeof(int) );
    *ret = a;
    *( ret + 1 ) = b;
    return ret;
}

// submit the codes above

int main() {
    int data[] = { 3 , 2 , 4 };
    twoSum( data , 3 , 6 );
    return 0;
}

