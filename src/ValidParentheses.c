//
// Created by seanr on 2016/2/14.
//

#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

int determineBracket( char ch ) {
    switch(ch){
        case '(':return 1;
        case '[':return 2;
        case '{':return 3;
        case ')':return -1;
        case ']':return -2;
        case '}':return -3;
        default:return 0;
    }
}

bool isValid(char* s) {
    int len = strlen(s);
    int cnt = len;
    char *pBuff = calloc( (size_t)len , sizeof(char) );
    int buffRear = 0;

    for( int i = 0 ; i < len ; i++ ) {
        char now = *( s + i );
        if( determineBracket( now ) > 0 ) {
            *( pBuff + buffRear ) = now;
            buffRear++;
        } else if( determineBracket( now ) < 0 ) {
            if( buffRear > 0 && ( determineBracket( *( pBuff + buffRear - 1 ) ) + determineBracket( now ) == 0 ) ) {
                buffRear--;
            } else {
                return false;
            }
        }
    }
	free( pBuff );
    if( buffRear > 0 ) {
        return false;
    }
    return true;

}

// submit the codes above

int main() {
    printf("%d\n" , isValid( "()[()(){()}]"));
    return 0;
}
