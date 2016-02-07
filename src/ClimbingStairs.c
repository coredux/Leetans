//
// Created by seanr on 2016/2/7.
//

#include <stdio.h>
#include <stdlib.h>

// submit the codes below


int climbStairs(int n) {

    int* dp = calloc( n + 1 , sizeof(int) );

    *dp = *( dp + 1 ) = 1;
    *(dp + 2) = 2;

    if( n > 2 ) {
        for( int i = 3 ; i <= n ; i++ ) {
            *( dp + i ) = *( dp + i - 1 ) + *( dp + i - 2 );
        }
    }
    return *(dp + n);

}

// submit the codes above

int main() {
    printf("%d\n" , climbStairs(38) );
    return 0;
}
