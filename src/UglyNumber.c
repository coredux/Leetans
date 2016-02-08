//
// Created by seanr on 2016/2/7.
//

#include <stdbool.h>
#include <stdio.h>

/*
 *  Note:
 *  1.when n = 0x 8000 0000 , -n == n
 *  2.n is not an ugly number when n <= 0
 *
 *
 * */

// submit the codes below


bool isUgly( int num ) {

    if( num <= 0 ) {
        return false;
    }

    while( num > 1 ) {

        if( ( num % 2 ) == 0 ) {
            num = num / 2;
        } else if ( ( num % 3 ) == 0 ) {
            num = num / 3;
        } else if( ( num % 5 ) == 0 ) {
            num = num / 5;
        } else {
            return false;
        }
    }
    return true;

}

// submit the codes above

int main() {
    printf("%d\n" , isUgly(-2));
    return 0;
}

