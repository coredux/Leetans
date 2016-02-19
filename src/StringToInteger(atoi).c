//
// Created by seanr on 2016/2/19.
//

#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>


// submit the codes below

int myAtoi(char* str) {

    unsigned int ret = 0;

    bool isPositive = true;
    int len = strlen(str);
    int idx = 0;
    while( idx < len ) {
        char ch = *( str + idx );
        if(  ch <= ' ' ) {
            idx++;
        } else {
            break;
        }
    }
    if( idx >= len ) {
        return 0;
    }
    if( *( str + idx ) == '+' ) {
        idx++;
    } else if( *( str + idx ) == '-' ) {
        isPositive = false;
        idx++;
    } else if( !( *(str + idx ) >= '0' && *( str + idx ) <= '9' ) ) {
        return 0;
    }
    while( idx < len ) {
        if( *( str + idx ) >= '0' && *( str + idx ) <= '9' ) {
            unsigned int now = ( unsigned int )( *( str + idx ) - '0' );
            if( ret > ( INT_MAX / 10 ) ) {
                return isPositive ? INT_MAX : INT_MIN ;
            } else if( ret == ( INT_MAX / 10 ) && isPositive && now > 7 ) {
                return INT_MAX;
            } else if( ret == ( INT_MAX / 10 ) && (!isPositive) && now > 8 ) {
                return INT_MIN;
            } else {
                ret = ret * 10 + now;
            }
        } else {
            break;
        }
        idx++;
    }
    if( isPositive ) {
        return (int)ret;
    }
    if( ret == INT_MIN  ) {
        return INT_MIN;
    }
    return (int)( -ret );

}

// submit the codes above

int main() {
    printf("%d\n" , myAtoi("+-2"));
    return 0;
}

