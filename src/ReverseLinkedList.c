//
// Created by seanr on 2016/2/7.
//

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

struct ListNode* reverseList(struct ListNode* head) {

    if( head == NULL || head->next == NULL ) {
        return head;
    }
    struct ListNode* newHead = reverseList( head->next );
    head->next->next = head;
    head->next = NULL;
    return newHead;

}

// submit the codes above

int main() {
    return 0;
}

