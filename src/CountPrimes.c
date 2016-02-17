//
// Created by seanr on 2016/2/18.
//

#include <stdlib.h>
#include <stdio.h>

// submit the codes below


int countPrimes(int n) {
    if( n <= 2 ) {
        return 0;
    }
    int oddsNum = ( n - 1 ) / 2 + 1;
    int* primeTable = calloc( (size_t)oddsNum , sizeof(int) );
    int cnt = 0;

    for( int i = 1 ; 2*i + 1 < n ; i++ ) {
        if( *( primeTable + i ) == 0 ) {
            *( primeTable + i ) =  1;
            for( int j = 3 ;  ( 2*i + 1 )*j < n ; j += 2 ) {
                int nowNum = ( 2*i + 1 ) * j;
                if( nowNum / 2 < oddsNum ) {
                    *( primeTable + nowNum / 2 ) = -1;
                }
            }
        }
        if( *( primeTable + i ) > 0 ) {
            cnt++;
        }
    }
    free( primeTable );
    return  cnt + 1;
}

// submit the codes above

int main() {
    printf("%d\n" , countPrimes( 5 ));
    return 0;
}

