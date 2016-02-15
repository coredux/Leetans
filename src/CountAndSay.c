//
// Created by seanr on 2016/2/14.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// submit the codes below

char* countAndSay( int n ){

    int stringSize = 100;
    int sizeLoad = 1;

    char* pre = calloc( (size_t)( stringSize * sizeLoad ) , sizeof(char) );
    char* now = calloc( (size_t)( stringSize * sizeLoad ) , sizeof(char) );
    *now = '1';

    for( int i = 0 ; i < n - 1 ; i++ ) {

        free( pre );
        pre = now;
        now = calloc( (size_t)( stringSize * sizeLoad ) , sizeof(char) );

        int preIndex = 0;
        int nowIndex = 0;
        int preLen = strlen( pre );

        while( preIndex < preLen ) {
            int cnt = 1;
            int appendBuffSize = 50;
            char *toAppend = calloc( ( size_t )appendBuffSize , sizeof(char) );

            char toCnt = *( pre + preIndex );
            int cntIndex = preIndex + 1;
            while( cntIndex < preLen && toCnt == *( pre + cntIndex )  ) {
                cntIndex += 1;
                cnt += 1;
            }
            preIndex = cntIndex;
            sprintf( toAppend , "%d%c" , cnt , toCnt );
            int appendLen = strlen( toAppend );

            // append
            if( nowIndex + appendLen >= stringSize * sizeLoad ) {
                char *tmp = calloc( (size_t)( stringSize * ( sizeLoad + 1 ) ) , sizeof(char) );
                memcpy( tmp , now , ( size_t )nowIndex );
                free( now );
                now = tmp;
                sizeLoad += 1;
            }
            strcat( now , toAppend );
            nowIndex += appendLen ;
            free( toAppend );

        }

    }
    free( pre );
    return now;

}

// submit the codes above

int main() {
    printf("%s\n" , countAndSay( 20 ) );
    return 0;
}

