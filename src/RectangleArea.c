//
// Created by seanr on 2016/2/13.
//

#include <stdio.h>

// submit the codes below

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    int minRightX = C < G ? C : G;
    int maxLeftX = A > E ? A : E;
    int minTopY = H < D ? H : D;
    int maxBottomY = F > B ? F : B;

    int overlapArea = 0;
    if( minRightX > maxLeftX && minTopY > maxBottomY ) {
        overlapArea = ( minRightX - maxLeftX ) * ( minTopY - maxBottomY );
    }

    return ( C - A ) * ( D - B ) + ( G - E ) * ( H - F ) - overlapArea;

}

// submit the codes above

int main() {
    return 0;
}

