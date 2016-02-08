//
// Created by seanr on 2016/2/8.
//

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

// submit the codes below

#define MAX_HAPPY_SUM 1000

int getHappySum( int n ) {

    int ret = 0;
    while( n != 0 ) {
        int lastBit = n - ( n / 10 ) * 10;
        n = n / 10;
        ret += lastBit * lastBit;
    }
    return ret;

}

bool isHappy(int n) {

    char showUp[ MAX_HAPPY_SUM ];
    memset( showUp , 0 , sizeof(char) * MAX_HAPPY_SUM );

    while( n != 1 ) {
        n = getHappySum( n );
        if( showUp[ n ] > 0 ) {
            return false;
        } else {
            showUp[ n ] += 1;
        }

    }

    return true;

}


// submit the codes above

int main() {
    printf("%d\n" , isHappy(19));
    return 0;
}

