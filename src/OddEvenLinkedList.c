//
// Created by seanr on 2016/2/2.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* );

int isOdd( int );

int main() {
    oddEvenList( NULL );
    return 0;
}

// not sure the oj supports stdbool.h
int isOdd( int val ) {
    return val%2;
}

struct ListNode* oddEvenList(struct ListNode* head ) {

    struct ListNode* retHead = head;

    if( retHead == NULL ) {
        return retHead;
    }

    struct ListNode* oddTail = head;
    struct ListNode* evenHead = head->next;
    int nowPos = 3;

    if( evenHead == NULL ) {
        return retHead;
    }

    struct ListNode* now = evenHead->next;
    struct ListNode* pre = evenHead;

    while( now != NULL ) {
        if( isOdd( nowPos ) ) { // move the odd node back to the oddTail
            pre->next = now->next;
            now->next = evenHead;
            oddTail->next = now;
            oddTail = now;
            now = pre->next;
        } else { // nothing to be done
            pre = now;
            now = now->next;
        }
        nowPos += 1;
    }

    return retHead;
}
