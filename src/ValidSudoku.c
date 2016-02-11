//
// Created by seanr on 2016/2/11.
//

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// submit the codes below

bool isValidNum( int *numArray , int nowNum ) {

    if( !( nowNum > 0 && nowNum < 10 ) ) {
        return false;
    }
    if( *( numArray + nowNum ) > 0 ) {
        return false;
    }
    return true;

}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {

    // grid size check
    if( boardRowSize % 3 != 0 ) {
        return false;
    }
    if( boardColSize % 3 != 0 ) {
        return false;
    }

    int num[10];

    // rowCheck
    for( int i = 0 ; i < boardRowSize ; i++ ) {
        memset( num , 0 , sizeof(int)*10 );
        char* row = *( board + i );
        for( int j = 0 ; j < boardColSize ; j++ ) {
            char now = *( row + j );
            if( now != '.' ) {
                int nowNum = atoi( &now );
                if( !isValidNum( num , nowNum ) ) {
                    return false;
                }
                num[ nowNum ] += 1;
            }
        }
    }

    // colCheck
    for( int i = 0 ; i < boardColSize ; i++ ) {
        memset( num , 0 , sizeof(int)*10 );
        for( int j = 0 ; j < boardRowSize ; j++ ) {
            char now = *( *( board + j ) + i );
            if( now!= '.' ) {
                int nowNum = atoi( &now );
                if( !isValidNum( num , nowNum ) ) {
                    return false;
                }
                num[ nowNum ] += 1;
            }
        }
    }

    // gridCheck
    memset( num , 0 , sizeof(int)*10 );
    int rowGrid = boardRowSize / 3;
    int colGrid = boardColSize / 3;
    for( int i = 0 ; i < rowGrid ; i++ ) {
        for( int j = 0 ; j < colGrid ; j++ ) {

            memset( num , 0 , sizeof(int)*10 );
            // row
            for( int m = 3*( i + 1 ) - 3 ; m < 3*( i + 1 )  ; m++ ) {
                // col
                for( int n = 3*(j + 1 ) - 3 ; n < 3*(j + 1 )  ; n++ ) {
                    char now = *( *( board + m ) + n );
                    if( now != '.' ) {
                        int nowNum = atoi( &now );
                        if( !isValidNum( num , nowNum ) ) {
                            return false;
                        }
                        num[ nowNum ] += 1;
                    }
                }
            }

        }

    }
    return true;


}

// submit the codes above

int main() {
    char *board[] = {
            "....5..1.",
            ".4.3.....",
            ".....3..1",
            "8......2.",
            "..2.7....",
            ".15......",
            ".....2...",
            ".2.9.....",
            "..4......"
    };
    printf("%d\n" , isValidSudoku( board , 9 , 9 ) );
    return 0;
}

