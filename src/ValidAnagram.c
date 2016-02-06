//
// Created by seanr on 2016/2/6.
//

#include <stdbool.h>
#include <string.h>
#include <stdio.h>


// submit the codes below

#define ASCII_RANGE 128

bool isAnagram(char* s, char* t) {

    int cntS[ ASCII_RANGE ];
    int cntT[ ASCII_RANGE ];

    memset( cntS , 0 , sizeof(int) * ASCII_RANGE );
    memset( cntT , 0 , sizeof(int) * ASCII_RANGE );

    for( int i = 0 ; i < strlen(s) ; i++ ) {
        char ch = *( s + i );
        cntS[ ch ] += 1;
    }

    for( int i = 0 ; i < strlen(t) ; i++ ) {
        char ch = *( t + i );
        cntT[ ch ] += 1;
    }

    for( int i = 0 ; i < ASCII_RANGE ; i++ ) {
        if( cntS[ i ] != cntT[ i ] ) {
            return false;
        }
    }
    return true;

}

// submit the codes above

int main() {

    printf("%d\n" , isAnagram( "abcdefg" , "gfedcba" ) );
    return 0;

}

