//
// Created by seanr on 2016/2/18.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

char* convert(char* s, int numRows) {
    if( numRows == 0 ) {
        return "";
    }
    if( numRows == 1 ) {
        return s;
    }
    int len = strlen( s );
    char** ret = calloc( (size_t)numRows , sizeof(char*) );
    int numCol = len + 1;
    for( int i = 0 ; i < numRows ; i++ ) {
        *( ret + i ) = calloc( ( size_t)numCol , sizeof(char) );
    }
    int n = numRows;
    for( int i = 0 ; i < len ; i++ ) {
        int preCycle = ( n - 1 ) * ( i / ( 2 * n - 2 ) );
        int tmp = i % ( 2*n - 2 );
        int row = 0 , col = 0;
        if( tmp >= n ) {
            row = 2*n - 2 - tmp;
            col = tmp - n + 1;
        } else {
            row = tmp;
            col = 0;
        }
        col += preCycle;
        *( *( ret + row ) + col ) = *( s + i );
    }
    char* retStr = calloc( (size_t)( len + 1 ) , sizeof(char) );
    int retIndex = 0;
    for( int i = 0 ; i < numRows ; i++ ) {
        for( int j = 0 ; j < numCol ; j++ ) {
            char ch = *( *( ret + i ) + j );
            if( ch != 0 ) {
                *( retStr + retIndex ) = ch;
                retIndex++;
            }
        }
    }
    for( int i = 0 ; i < numRows ; i++ ) {
        free( *( ret + i ) );
    }
    free(ret);
    return retStr;
}

// submit the codes above

int main() {
    printf("%s\n", convert( "PAYPALISHIRING" , 4 ) );
    return 0;
}

