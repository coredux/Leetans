#include <iostream>
#include <random>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// submit the codes below

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head):  _rdEngine(_rdevice()) {
        this->_head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int idx = 1;
        int retNum = this->_head->val;
        ListNode* now = this->_head;
        while( now != NULL ) {
            std::uniform_int_distribution<int> uni(1, idx);
            int randInt = uni( this->_rdEngine);
            if ( randInt == idx ) {
                retNum = now->val;
            }
            ++idx;
            now = now->next;
        }
        return retNum;
    }

private:
    ListNode* _head;
    std::random_device _rdevice;
    std::mt19937 _rdEngine;
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}