//
// Created by seanr on 2016/2/6.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// submit the codes below

#define MAX_OUTPUT_LENGTH 128

char* getHint( char* secret , char* guess ) {
    int sLen = strlen( secret );
    int gLen = strlen( guess );

    if( sLen != gLen ) {
        return NULL;
    }

    char *sec = calloc( sLen , sizeof(char) );
    memcpy( sec , secret , sLen );

    char *gue = calloc( gLen , sizeof(char) );
    memcpy( gue , guess , gLen );


    int numA = 0;
    int numB = 0;

    for( int i = 0 ; i < sLen ; i++ ) {
        char* chSec = sec + i ;
        char* chGue = gue + i ;
        if( *chSec == *chGue ) {
            numA += 1;
            *chGue = '#';
            *chSec = '#';
        }
    }

    for( int i = 0 ; i < sLen ; i++ ) {
        char* chSec = sec + i;
        if( *chSec == '#' ) {
            continue;
        }

        for( int j = 0 ; j < gLen ; j++ ) {
            char* chGue = gue + j;
            if( *chGue == '#' ) {
                continue;
            }

            if( *chGue == *chSec ) {
                numB += 1;
                *chGue = '#';
                *chSec = '#';
            }

        }
    }

    free( sec );
    free( gue );

    char *ret = calloc( MAX_OUTPUT_LENGTH , sizeof(char) );
    sprintf( ret , "%dA%dB" , numA , numB );
    return ret;
}

// submit the codes above

int main() {

    char* sec = "1123";
    char* gue = "0111";

    puts( getHint( sec , gue ) );

    return 0;

}

