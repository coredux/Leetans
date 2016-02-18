//
// Created by seanr on 2016/2/18.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// submit the codes below

char* convertToTitle(int n) {
    int maxLength = 100;
    char* ret = calloc( (size_t)maxLength  , sizeof(char) );
    int retIndex = 0;
    while( n > 0 ) {
        int last =  ( n - 1 ) % 26;
        char lastBit =(char)( 'A' + last );
        *( ret + retIndex ) = lastBit;
        retIndex++;
        if( retIndex == maxLength ) {
            char* newRet = calloc( (size_t)( 2 * maxLength ) , sizeof(char) );
            memcpy( newRet , ret , (size_t)retIndex );
            free( ret );
            ret = newRet;
            maxLength *= 2;
        }
        n = ( n - 1 ) / 26;
    }
    int left = 0 , right = retIndex - 1;
    while( left < right ) {
        char tmp = *( ret + left );
        *( ret + left ) = *( ret + right );
        *( ret + right ) = tmp;
        left++;
        right--;
    }
    return ret;

}

// submit the codes above

int main() {
    printf("%s\n" , convertToTitle( 26 ));
    return 0;
}

