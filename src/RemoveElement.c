//
// Created by seanr on 2016/2/10.
//

#include <stddef.h>
#include <stdbool.h>

// submit the codes below

int removeElement(int* nums, int numsSize, int val) {

    if( nums == NULL ) {
        return 0;
    }

    for( int i = 0 ; i < numsSize ; i++ ) {
        if( *( nums + i ) == val ) {
            bool isFound = false;
            int foundPlace = 0;
            for( int j = i + 1 ; j < numsSize ; j++ ) {
                if( *( nums + j ) != val ) {
                    isFound = true;
                    foundPlace =  j ;
					break;
                }
            }
            if( !isFound ) {
                return i;
            }
            *( nums + i ) = *( nums + foundPlace );
            *( nums + foundPlace ) = val;
        }
    }
    return numsSize;

}

// submit the codes above

int main() {
    return 0;
}

