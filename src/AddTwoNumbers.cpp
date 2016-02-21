#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode( int x ) : val( x ) , next( NULL ) {}
};

// submit the codes below

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* retHead = new ListNode( 0 );
        ListNode* now = retHead;
        while( true ) {
            int a = this->getNodeVal( l1 );
            int b = this->getNodeVal( l2 );
            int tmp = a + b + carry;
            if( tmp > 9 ) {
                carry = 1;
                now->next = new ListNode( tmp - 10 );
                now = now->next;
            } else if( tmp > 0 && tmp < 10 ) {
                carry = 0;
                now->next = new ListNode( tmp );
                now = now->next;
            } else if( tmp == 0 && l1 == NULL && l2 == NULL ){
                break;
            } else {
                carry = 0;
                now->next = new ListNode( tmp );
                now = now->next;
            }
            if( l1 != NULL ) {
                l1 = l1->next;
            }
            if( l2 != NULL ) {
                l2 = l2->next;
            }
        }

        if( retHead->next != NULL ) {
            now = retHead;
            retHead = retHead->next;
            delete( now );
        }
        return retHead;
    }

private:

    int getNodeVal( ListNode* pNode ) {
        int ret = 0;
        if( pNode != NULL ) {
            ret = pNode->val;
        }
        return ret;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}