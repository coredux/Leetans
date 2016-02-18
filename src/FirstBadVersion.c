//
// Created by seanr on 2016/2/18.
//

#include <stdbool.h>
#include <stdio.h>

#define MAX_VERSION 100

bool vTable[ MAX_VERSION ];

bool isBadVersion(int version) {
    if( version < 1702766719 ) {
        return false;
    }
    return true;
}

// submit the codes below

int firstBadVersion(int n) {

    int left = 0 , right = n;
    while( left < right ) {
        int mid =  left / 2 + right  / 2;
        if( isBadVersion( mid ) ) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;

}

// submit the codes above

int main() {
    printf("%d\n" , firstBadVersion( 2126753390 ));
    return 0;
}

