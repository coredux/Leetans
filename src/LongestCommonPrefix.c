//
// Created by seanr on 2016/2/16.
//

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


// submit the codes below

char* longestCommonPrefix(char** strs, int strsSize) {
    if( strs == NULL || strsSize == 0 ) {
        return "";
    }
    char* shortestStr = *strs;
    int shortestLen = strlen( *strs );
    for( int i = 0 ; i < strsSize ; i++ ) {
        int nowLen = strlen( *( strs + i ) );
        if( nowLen < shortestLen ) {
            shortestLen = nowLen;
            shortestStr = *( strs + i );
        }
    }

    for( int i = shortestLen ; i >= 0 ; i-- ) {
        int prefixLen = i;
        char* nowPrefix = calloc( (size_t) prefixLen  , sizeof(char) );
        memcpy( nowPrefix , shortestStr , (size_t ) prefixLen  );
        bool isEqualStr = true;
        for( int j = 0 ; j < strsSize ; j++ ) {
            char* nowStr = calloc( (size_t) prefixLen , sizeof(char) );
            memcpy( nowStr , *(strs + j ) , ( size_t )prefixLen );
            if( strcmp( nowPrefix , nowStr ) != 0 ) {
                isEqualStr = false;
                free( nowStr );
                break;
            }
            free( nowStr );
        }
        if( isEqualStr ) {
            return nowPrefix;
        } else {
            free( nowPrefix );
        }
    }
    return "";

}

// submit the codes above

int main() {
    char *strs[] = {
            "hello" ,
            "hello" ,
            "hello" ,
    };
    printf("%s\n" , longestCommonPrefix( strs , 3 ) );
    return 0;
}

