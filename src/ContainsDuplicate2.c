//
// Created by seanr on 2016/2/12.
//

#include <stdlib.h>
#include <stdbool.h>

// submit the codes below


bool containsNearbyDuplicate(int* nums, int numsSize, int k) {

    if( nums == NULL ) {
        return false;
    }

    for( int i = 0 ; i < numsSize ; i++ ) {
        for( int j = i + 1 ; j < numsSize && j <= i + k ; j ++ ) {
            if( *( nums + i ) == *(nums + j ) ) {
                return true;
            }
        }
    }
    return  false;


}


// submit the codes above

int main() {
    return 0;
}

