//
// Created by seanr on 2016/2/6.
//

#include <string.h>
#include <stdio.h>

// submit the codes below

int titleToNumber(char* s) {

    int numLen = strlen( s );
    int ans = 0;

    for( int i = 0 ; i < numLen ; i++ ) {
        char nowBit = *( s + i );
        int val = nowBit - 'A' + 1;
        ans = ans * 26 + val;
    }
    return ans;

}

// submit the codes above

int main() {
    printf("%d\n" , titleToNumber("AB") );
    return 0;
}



