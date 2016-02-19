//
// Created by seanr on 2016/2/19.
//

#include <string.h>
#include <stdio.h>

// submit the codes below

int getSubVersion( char* version , int length , int* nowIndex ) {

    int subv = 0;
    int idx = *nowIndex;

    while( idx < length ) {
        char ch = *( version + idx );
        if( ch == '.' ) {
            break;
        } else {
            subv *= 10;
            subv += ( ch - '0' );
            idx++;
        }
    }
    *nowIndex = idx;

    return subv;

}

int compareVersion(char* version1, char* version2) {

    int len1 = strlen( version1 );
    int len2 = strlen( version2 );

    int idx1 = 0;
    int idx2 = 0;

    while( idx1 < len1 || idx2 < len2 ) {
        int subv1 = getSubVersion( version1 , len1 , &idx1 );
        int subv2 = getSubVersion( version2 , len2 , &idx2 );
        if( subv1 > subv2 ) {
            return 1;
        } else if( subv1 < subv2 ) {
            return -1;
        } else {
            idx1++;
            idx2++;
        }
    }
    return 0;
}

// submit the codes above

int main() {
    printf("%d\n" , compareVersion( "01" , "1" ) );
    return 0;
}

