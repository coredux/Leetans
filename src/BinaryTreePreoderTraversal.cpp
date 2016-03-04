#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// submit the codes below

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> travStack;
        vector<int> ret;
        travStack.push( root );
        while( !travStack.empty() ) {
            TreeNode* now = travStack.top();
            travStack.pop();
            if( now != NULL ) {
                ret.push_back( now->val );
            }
            if( now != NULL ) {
                travStack.push( now->right );
                travStack.push( now->left );
            }
        }
        return ret;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}