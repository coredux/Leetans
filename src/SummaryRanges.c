//
// Created by seanr on 2016/2/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// submit the codes below

char* getRangeStr( int leftNum , int rightNum ) {
    int rangeStrLen = 20;
    char* tmpRangeStr = calloc( (size_t)rangeStrLen , sizeof(char) );
    if( leftNum != rightNum ) {
        sprintf( tmpRangeStr , "%d->%d" , leftNum , rightNum );
    } else {
        sprintf( tmpRangeStr , "%d" , leftNum );
    }
    return tmpRangeStr;
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {

    if( nums == NULL || numsSize == 0) {
        return NULL;
    }

    int numRanges = 100;
    char** ret = calloc( (size_t)numRanges , sizeof(char*) );

    int left = 0 , right = 0;
    int rangeIndex = 0;

    for( int i = 0 ; i < numsSize - 1 ; i++ ) {
        right = i;
        if(  *( nums + i ) + 1 != *( nums + i + 1 ) ) {
            char* tmpRangeStr = getRangeStr( *( nums + left ) , *( nums + right ) );
            *( ret + rangeIndex ) = tmpRangeStr;
            rangeIndex++;
            left = i + 1;
        }
        if( rangeIndex == numRanges ) {
            char** newRet = calloc( (size_t)( 2 * numRanges ) , sizeof(char*) );
            memcpy( newRet , ret , sizeof(ret) );
            free( ret );
            ret = newRet;
            numRanges *= 2;
        }
    }
    if( numsSize > 1 ) {
        right = numsSize - 1;
        if( *( nums + right - 1 ) + 1 != *( nums + right ) ) {
            char* tmpRangeStr =  getRangeStr( *( nums + right ) , *( nums + right ) );
            *( ret + rangeIndex ) = tmpRangeStr;
            rangeIndex++;
        } else {
            char* tmpRangeStr = getRangeStr( *( nums + left ) , *( nums + right ) );
            *( ret + rangeIndex ) = tmpRangeStr;
            rangeIndex++;
        }
    } else {
        char* tmpRangeStr = getRangeStr( *nums , *nums );
        *( ret + rangeIndex ) = tmpRangeStr;
        rangeIndex++;
    }
    *returnSize = rangeIndex;
    return ret;

}

// submit the codes above

int main() {
    return 0;
}

