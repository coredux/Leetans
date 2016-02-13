//
// Created by seanr on 2016/2/13.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if( head == NULL ) {
        return NULL;
    }
    struct ListNode** pWindow = calloc( (size_t) n , sizeof( struct ListNode* ) );
    struct ListNode** pPreWindow  = calloc( (size_t) n , sizeof(struct ListNode* ) );
    struct ListNode* pre = NULL;
    struct ListNode* now = head;
    int windowCnt = 0;
    int total = 0;
    while( now != NULL ) {
        if( windowCnt == n ) {
            windowCnt = 0;
        }
        *( pWindow + windowCnt ) = now;
        *( pPreWindow + windowCnt ) = pre;
        windowCnt += 1;
        pre = now;
        now = now->next;
        total += 1;
    }
    int rmPos = total % n;
    now = *( pWindow + rmPos );
    pre = *( pPreWindow + rmPos );

    if( pre == NULL ) {
        struct ListNode* ret = now->next;
        free( now );
        return ret;
    }
    pre->next = now->next;
    free( now );
    return head;
}

// submit the codes above

int main() {
    struct ListNode* head = calloc( 1 , sizeof(struct ListNode) );
    head->val = 1;
    int restLen = 1;
    struct ListNode* pre = head;
    for( int i = 0 ; i < restLen ; i++ ) {
        pre->next = calloc( 1 , sizeof( struct ListNode) );
        pre = pre->next;
        pre->val = i + 2;
    }
    head = removeNthFromEnd( head , 1 );
    while( head != NULL ) {
        printf("%d\n" , head->val );
        head = head->next;
    }
    return 0;
}

