//
// Created by seanr on 2016/2/13.
//

#include <stdint.h>
#include <stdio.h>

// submit the codes below


uint32_t reverseBits(uint32_t n) {
    int ret = 0;
    int moveCnt = 0;
    while( n > 0 ) {
        ret = ret | ( n & 1 );
        n = n >> 1;
        if( moveCnt < 31 ) {
            ret = ret << 1;
            moveCnt += 1;
        }
    }
    for( int i = 0 ; i < 31 - moveCnt ; i++ ) {
        ret = ret << 1;
    }
    return ret;
}

// submit the codes above

int main() {
    uint32_t a = 43261596;
    printf("%u\n" , reverseBits( 2147483648 ) );
    return 0;
}

