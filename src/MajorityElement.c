//
// Created by seanr on 2016/2/6.
//

#include <stdlib.h>
#include <stdio.h>

// submit the codes below

int cmp( const void* a , const void* b ) {
    return *( int* ) a - *( int* ) b;
}

int majorityElement(int* nums, int numsSize) {

    qsort( nums , ( size_t )numsSize , sizeof(int) , cmp );

    int cnt = 1;

    for( int i = 1 ; i < numsSize ; i++ ) {

        int nowNum = *( nums + i );
        int preNum = *( nums + i - 1 );

        if( nowNum == preNum ) {
            cnt += 1;
            if( cnt > ( numsSize / 2 ) ) {
                return nowNum;
            }
        } else {
            cnt = 1;
        }

    }
    return *nums;

}

// submit the codes above


int main() {
    int data[] = { 1 , 2  , 3 , 1 , 1 };
    printf("%d\n" , majorityElement( data , 5 ) );
    return 0;
}

