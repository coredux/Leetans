//
// Created by seanr on 2016/2/11.
//

#include <stdio.h>

// submit the codes below

int trailingZeroes(int n) {
    int cnt = 0;
    while( n > 1 ) {
        cnt += ( n / 5 );
        n /= 5;
    }
    return cnt;
}

// submit the codes above

int main() {
    for( int i = 0 ; i < 31; i++ ) {
        printf("%d:%d\n" , i  , trailingZeroes( i ) );
    }
    return 0;
}

