//
// Created by seanr on 2016/2/17.
//

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

bool isPalindrome(char* s) {

    if( s == NULL ) {
        return true;
    }

    int len = strlen(s);
    char* newStr = calloc( (size_t)( len + 1) , sizeof(char) );
    int indexNewStr = 0;
    for( int i = 0 ; i < len ; i++ ) {
        char ch = *( s + i );
        if( ( ch >= 'a' && ch <= 'z' ) || ( ch >= '0' && ch <= '9' ) ) {
            *( newStr + indexNewStr ) = ch;
            indexNewStr++;
        } else if( ch >= 'A' && ch <= 'Z' ) {
            *( newStr + indexNewStr ) = ( char )( ch + ( 'a' - 'A' ) );
            indexNewStr++;
        }
    }
    int newLen = indexNewStr;
    if( newLen < 2 ) {
        free( newStr );
        return true;
    }
    int headIndex = 0;
    int tailIndex = newLen - 1;
    while( headIndex < tailIndex ) {
        if( *( newStr + headIndex ) != *( newStr + tailIndex ) ) {
            free( newStr );
            return false;
        }
        headIndex++;
        tailIndex--;
    }
    free( newStr );
    return true;
}

// submit the codes above

int main() {
    printf("%d\n" , isPalindrome("race a car"));
    return 0;
}

