//
// Created by seanr on 2016/2/7.
//

#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode* now = head;
    while( now != NULL && now->next != NULL ) {
        if( now->val == now->next->val ) {
            struct ListNode* temp = now->next;
            now->next = now->next->next;
            free( temp );
        } else {
            now = now->next;
        }
    }
    return head;

}

// submit the codes above

int main() {
    return 0;
}

