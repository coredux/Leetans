//
// Created by seanr on 2016/2/17.
//

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

struct ListNode* reverseList( struct ListNode* head ) {
    if( head == NULL || head->next == NULL ) {
        return head;
    }
    struct ListNode* newHead = reverseList( head->next );
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome(struct ListNode* head) {

    if( head == NULL || head->next == NULL ) {
        return true;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while( fast->next != NULL && fast->next->next != NULL ) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* midHead = slow;
    midHead->next = reverseList( midHead->next );
    midHead = midHead->next;

    struct ListNode* now = head;
    while( midHead != NULL ) {
        if( now->val != midHead->val ) {
            return false;
        }
        now = now->next;
        midHead = midHead->next;
    }
    return true;
}

// submit the codes above

int main() {
    struct ListNode* head = calloc( 1 , sizeof(struct ListNode) );
    head->val = 1;
    head->next = calloc( 1 , sizeof(struct ListNode) );
    head->next->val = 2;
    head->next->next = calloc( 1 , sizeof(struct ListNode) );
    head->next->next->val = 3;
    isPalindrome( head );
    return 0;
}

