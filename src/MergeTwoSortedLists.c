//
// Created by seanr on 2016/2/8.
//


#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};


// submit the codes below

int listLen( struct ListNode* head ) {

    int len = 0;
    while( head != NULL ) {
        len += 1;
        head = head->next;
    }
    return len;

}

int* listsToArray( int listsNum , struct ListNode** pListHeads , int* toSaveTotalLen ) {

    int totalLen = 0;
    int *lens = calloc( ( size_t )listsNum , sizeof(int) );

    for( int i = 0 ; i < listsNum ; i++ ) {
        struct ListNode* nowListHead = *( pListHeads + i );
        int nowLen = listLen( nowListHead );
        *( lens + i ) = nowLen;
        totalLen += nowLen;
    }

    *toSaveTotalLen = totalLen;

    int* lists = calloc( ( size_t )totalLen , sizeof(int) );
    int offset = 0;

    for( int i = 0 ; i < listsNum ; i++ ) {
        struct ListNode* nowListHead = *( pListHeads + i );
        int nowLen = *( lens + i );
        for( int j = 0 ; j < nowLen ; j++ ) {
            *( lists + offset ) = nowListHead->val;
            nowListHead = nowListHead->next;
            offset += 1;
        }

    }

    return lists;

}

int cmp( const void *a , const void *b ) {
    return *(int*)a - *(int*)b;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode** listsHeads = calloc( ( size_t )2 , sizeof(struct ListNode*) );
    *listsHeads = l1;
    *( listsHeads + 1 ) = l2;
    int totalLen = 0;
    int* lists = listsToArray( 2 , listsHeads , &totalLen );
    qsort( lists , ( size_t )totalLen , sizeof(int) , cmp );

    struct ListNode* merged = NULL;
    if( totalLen > 0 ) {
        merged = calloc( ( size_t )1 , sizeof(struct ListNode ) );
    } else {
        return NULL;
    }

    struct ListNode* pre = merged;
    merged->val = *( lists );

    for( int i = 1 ; i < totalLen ; i++ ) {
        struct ListNode* now = calloc( ( size_t )1 , sizeof(struct ListNode ) );
        pre->next = now;
        now->val = *( lists + i );
        pre = now;
    }

    return merged;

}

// submit the codes above

int main() {
    return 0;
}

