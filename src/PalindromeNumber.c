//
// Created by seanr on 2016/2/11.
//

#include <stdbool.h>
#include <stdio.h>

// submit the codes below

bool isPalindrome(int x) {
    if( x < 0 ) {
        return false;
    }
    int dummy = 0;
    int orig = x;
    while( x > 9 ) {
        dummy = dummy * 10 + x % 10;
        x = x / 10;
    }
    /* *note:
     * the reversed integer might overflow
     * */
    return ( dummy == ( orig / 10 ) ) && ( orig % 10 == x);

}

// submit the codes above

int main() {
    printf("%d\n" , isPalindrome( 223322 ) );
    return 0;
}

