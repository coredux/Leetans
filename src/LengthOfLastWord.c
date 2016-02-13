//
// Created by seanr on 2016/2/13.
//

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// submit the codes below

bool isCh( char ch ) {
    return isdigit( ch ) | isalpha( ch );
}

int lengthOfLastWord(char* s) {
    if( s == NULL ) {
        return 0;
    }
    int len = strlen(s);
    int preWordLen = 0;
    int nowWordLen = 0;
    int nowWordIndex = 0;
    while( nowWordIndex < len ) {
        char now = *( s + nowWordIndex );
        if( now == ' ' ) {
            while( nowWordIndex < len && !isCh( *( s + nowWordIndex ) ) ) {
                nowWordIndex += 1;
            }
            preWordLen = nowWordLen;
            nowWordLen = 0;
        } else if ( isCh( now ) ) {
            nowWordLen += 1;
            nowWordIndex += 1;
        }
    }
    return nowWordLen > 0 ? nowWordLen : preWordLen;

}

// submit the codes above

int main() {
    printf("%d\n" , lengthOfLastWord( "Hello world    a     " ));
    return 0;
}
