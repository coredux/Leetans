//
// Created by seanr on 2016/2/10.
//

#include <stddef.h>
#include <stdlib.h>

// submit the codes below

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    if( digits == NULL || digitsSize == 0 ) {
        return NULL;
    }
    int carry = 1;
    for( int i = digitsSize - 1 ; i >= 0 ; i-- ) {
        if( *( digits + i ) + carry > 9 ) {
            *( digits + i ) += carry - 10;
            carry = 1;
        } else {
            *( digits + i ) += carry;
            carry = 0;
        }
    }
    if( carry == 0 ) {
        *returnSize = digitsSize;
        return digits;
    } else {
        int *ret = calloc( (size_t)( digitsSize + 1 ) , sizeof(int) );
        *returnSize = digitsSize + 1;
        *ret = carry;
        for( int i = 0 ; i < digitsSize ; i++ ) {
            *( ret + i + 1 ) = *( digits + i );
        }
        return ret;
    }

}

// submit the codes above

int main() {
    return 0;
}

