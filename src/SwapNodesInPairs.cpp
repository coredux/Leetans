#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode( int x ) : val( x ) {}
};

// submit the codes below

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == NULL || head->next == NULL ) {
            return head;
        }
        ListNode* newHead = head->next;
        ListNode* now = head;
        ListNode* pre = NULL;
        ListNode* after;

        while ( now != NULL && now->next != NULL ) {
            after = now->next;
            now->next = after->next;
            after->next = now;
            if( pre != NULL ) {
                pre->next = after;
            }
            pre = now;
            now = now->next;
        }
        return newHead;
    }
};

// submit the codes above

int main() {
    return 0;
}