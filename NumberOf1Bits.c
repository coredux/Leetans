#include <stdbool.h>
#include <stdio.h>

bool isPowerOfTwo(int n) {
    return (n>0)&&(!(n&(~(-n))));
}

int main() {
    printf("%d\n" , isPowerOfTwo( 0 ) );
    return 0;
}