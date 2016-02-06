//
// Created by seanr on 2016/2/6.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


// submit the codes below

#define MAX_SLOT 0x4000000
#define INT_RIGHTMOVE_BIT 5
#define INT_MOD_NUM 0x1f

bool containsDuplicate(int* nums, int numsSize) {

    int* cntPos = calloc( MAX_SLOT , sizeof(int) );
    int* cntNeg = calloc( MAX_SLOT , sizeof(int) );

    for( int i = 0 ; i < numsSize ; i++ ) {
        int num = *( nums + i );
        int* destCntArr = NULL;
        if( num >= 0 ) {
            destCntArr = cntPos;
        } else {
            num = -num;
            destCntArr = cntNeg;
        }
        int posit = num >> INT_RIGHTMOVE_BIT;
        int offsetInSlot = num & INT_MOD_NUM;
        int orSlotNum =  1 << offsetInSlot;
        int oldSlot = *( destCntArr + posit );
        if( ( oldSlot & orSlotNum ) != 0 ) {
            return true;
        } else {
            *( destCntArr + posit ) = oldSlot | orSlotNum ;
        }

    }
    return false;

}

// submit the codes above

int main() {
    int data[] = { 501982, 501982, 3, 4, 1 };
    int* pData = data;

    printf("%d\n" , containsDuplicate( pData , 5 ) );
    return 0;
}


