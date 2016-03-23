#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode( int x ) : val( x ) , left( NULL ) , right( NULL ) {}
};

// submit the codes below

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        pushTreeIntoTravelStack( root );

        int cnt = 0;
        while( !travelStk.empty() ) {
            TreeNode* now = travelStk.top();
            ++cnt;
            travelStk.pop();
            if( now->right != NULL ) {
                pushTreeIntoTravelStack( now->right );
            }
            if( cnt == k ) {
                return now->val;
            }
        }
        throw 0;
    }

private:
    stack<TreeNode*> travelStk;

    void pushTreeIntoTravelStack( TreeNode* root ) {

        while ( root != NULL ) {
            travelStk.push( root );
            root = root->left;
        }

    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}