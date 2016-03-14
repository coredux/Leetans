#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode( int x ) : val( x ) , next( NULL ) {}
};

// submit the codes below

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *fast = head;
        ListNode *slow = head;

        while( fast != NULL && fast->next != NULL && slow != NULL ) {
            fast = fast->next->next;
            slow = slow->next;
            if( fast == slow ) {
                return true;
            }
        }
        return false;

    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}