//
// Created by seanr on 2016/2/17.
//

#include <stdio.h>


// submit the codes below

int reverse(int x) {
    int posiEdge = 0x7fffffff;
    int negeEdge = 0x80000000;
    int rev = 0;
    while( x > 9 || x < -9 ) {
        rev = rev * 10;
        rev += x - x / 10 * 10;
        x = x / 10;
    }
    if( rev > ( posiEdge / 10 ) || rev < ( negeEdge / 10 ) ) {
        return 0;
    }
    if( ( rev == ( posiEdge / 10 ) && x > 7 ) || ( rev == ( negeEdge / 10 ) && x < -8 ) ){
        return 0;
    }
    return rev * 10 + x;

}

// submit the codes above

int main() {
    printf("%d\n" , reverse(-123) );
    return 0;
}

