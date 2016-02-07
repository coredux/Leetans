//
// Created by seanr on 2016/2/7.
//

#include <string.h>
#include <stdio.h>

// submit the codes below

int romanCharToInt( char ch ) {
    int ret = 0;
    switch (ch) {
        case 'I': ret = 1;
            break;
        case 'V': ret = 5;
            break;
        case 'X': ret = 10;
            break;
        case 'L': ret = 50;
            break;
        case 'C': ret = 100;
            break;
        case 'D': ret = 500;
            break;
        case 'M': ret = 1000;
            break;
        default: ret = 0;
            break;
    }
    return ret;
}

int romanToInt(char* s) {

    int lastNum = 0;
    int sum = 0;

    for( int i = strlen(s) - 1 ; i >= 0 ; i-- ) {
        int nowNum = romanCharToInt( *( s + i ) );
        if( lastNum > nowNum ) {
            sum = sum - nowNum;
        } else {
            sum = sum + nowNum;
        }

        lastNum = nowNum;

    }
    return sum;

}

// submit the codes above

int main() {
    printf("%d\n" , romanToInt( "MDCCCLXXXVIII" ) );
    return 0;
}
