//
// Created by seanr on 2016/2/6.
//

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// submit the codes below

void deleteNode(struct ListNode* node) {

    struct ListNode* afterOne = node->next;
    node->val = afterOne->val;
    node->next = afterOne->next;
    free( afterOne );

}

// submit the codes above

int main() {
    return 0;
}

