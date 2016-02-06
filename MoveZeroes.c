//
// Created by seanr on 2016/2/6.
//

#include <stdio.h>
#include <stdbool.h>

// submit the codes below

void moveZeroes(int* nums, int numsSize) {

    bool isOrdered = false;

    for( int i = 0 ; i < numsSize ; i++ ) {
        if( isOrdered ) {
            break;
        }
        if( *( nums + i ) == 0 ) {
            bool isSwapted = false;
            for( int j = i + 1 ; j < numsSize ; j++ ) {
                if( *( nums + j ) != 0 ) {
                    int temp = *( nums + j );
                    *( nums + j ) = *( nums + i );
                    *( nums + i ) = temp;
                    isSwapted = true;
                    break;
                }
            }
            if( !isSwapted ) {
                isOrdered = true;
            }
        }
    }

}

// submit the codes above

int main() {
    int data[] = { 1 , 0 , 0 , 0 , 1 };
    int numSize = 1;
    moveZeroes( data , numSize );
    for( int i = 0 ; i < numSize ; i++ ) {
        printf("%d," , data[i] );
    }
    printf("\n");
    return 0;
}