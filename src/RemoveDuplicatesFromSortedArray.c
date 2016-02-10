//
// Created by seanr on 2016/2/10.
//

#include <stddef.h>
#include <stdbool.h>


int _removeDuplicates(int* nums, int numsSize) {
    if( nums == NULL || numsSize == 0 ) {
        return 0;
    }

    for( int i = 1 ; i < numsSize ; i++ ) {
        int preVal = *( nums + i - 1 );
        int nowVal = *( nums + i );
        if( nowVal <= preVal ) {
            bool isFound = false;
            int foundPos = 0;
            for( int j = i + 1 ; j < numsSize ; j++ ) {
                if( *( nums + j ) > preVal ) {
                    isFound = true;
                    foundPos = j;
                    break;
                }
            }
            if( !isFound ) {
                return i;
            }
            int temp = *( nums + i );
            *( nums + i ) = *( nums + foundPos );
            *( nums + foundPos ) = temp;
        }
    }
    return numsSize;

}

// submit the codes below

int removeDuplicates( int* nums , int numsSize ) {

    if( nums == NULL || numsSize == 0 ) {
        return 0;
    }
    int notDupIndex = 0;
    for( int i = 0 ; i < numsSize; i++ ) {
        if( *( nums + i ) > *( nums + notDupIndex ) ) {
            *( nums + notDupIndex + 1 ) = *( nums + i );
            notDupIndex += 1;
        }
    }
    return notDupIndex + 1;
}

// submit the codes above

int main() {
    return 0;
}

