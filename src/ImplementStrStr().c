//
// Created by seanr on 2016/2/17.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

int strStr(char* haystack, char* needle) {

    int hayLen = strlen( haystack );
    int neeLen = strlen( needle );

    if( neeLen < 1 ) {
        return 0;
    }

    int* next = calloc( (size_t)( neeLen + 1 ) , sizeof(int) );
    int neeIndex = 0;
    *next = -1;
    int cmpPos = -1;
    while( neeIndex < neeLen ) {
        if( cmpPos == -1 || *( needle + neeIndex ) == *( needle + cmpPos ) ) {
            neeIndex++;
            cmpPos++;
            *( next + neeIndex ) = cmpPos;
        } else {
            cmpPos = *( next + cmpPos );
        }
    }

    int hayIndex = 0;
    neeIndex = 0;
    while( hayIndex < hayLen ) {
        if( neeIndex == -1 || *( haystack + hayIndex ) == *( needle + neeIndex ) ) {
            hayIndex++;
            neeIndex++;
        } else {
            neeIndex = *( next + neeIndex );
        }

        if( neeIndex == neeLen ) {
            return hayIndex - neeLen;
        }
    }
    free(next);
    return -1;

}

// submit the codes above
int main() {
    printf("%d\n" , strStr( "mississippi", "issipi" ) );
    return 0;
}

