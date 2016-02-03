#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPowerOfThree(int n) {
    // 卡精度,一直WA在1e-8
    double eps = 1e-10;
    double x = log(n) / log(3);
    return ( n > 0 ) && (  fabs( x - (double)(int)( x + 0.5 ) ) <  eps );

}

int main() {
    printf("%d\n" , isPowerOfThree( 19682 ) );
    return 0;
}