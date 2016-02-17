//
// Created by seanr on 2016/2/17.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

int getVal( char ch ) {
    if( ch == '0' ) {
        return 0;
    } else if( ch == '1' ) {
        return 1;
    } else {
        return 0;
    }
}

char* addBinary(char* a, char* b) {

    int aLen = strlen( a );
    int bLen = strlen( b );

    if( bLen > aLen ) {
        char* tmp = a;
        int tmpLen = aLen;

        a = b;
        b = tmp;

        aLen = bLen;
        bLen = tmpLen;

    }

    char* ret = calloc( (size_t)( aLen + 2 ) , sizeof(char) );
    int retPos = aLen;
    int aPos = aLen - 1;
    int bPos = bLen - 1;
    int carry = 0;
    while( aPos >= 0 ) {
        int nowVal = getVal( *( a + aPos ) );
        nowVal += carry;
        if( bPos >= 0 ) {
            nowVal += getVal( *( b + bPos ) );
        }
        if( nowVal > 1 ) {
            carry = 1;
            nowVal -= 2;
        } else {
            carry = 0;
        }
        if( nowVal == 1 ) {
            *( ret + retPos ) = '1';
        } else {
            *( ret + retPos ) = '0';
        }
        retPos--;
        aPos--;
        bPos--;
    }
    if( carry == 1 ) {
        *( ret + retPos ) = '1';
    } else {
        char *newRet = calloc( (size_t)( aLen + 1 ) , sizeof(char) );
        memcpy( newRet , ret + 1 , (size_t )aLen );
        free( ret );
        ret = newRet;
    }
    return ret;
}

// submit the codes above

int main() {
    printf("%s\n" , addBinary( "11011011111101010000111011101100000111101011111111010111" ,
                                 "100001000110011010100001100001001101001010000101111110" ) );
    return 0;
}

