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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> travelStk;
        travelStk.push( root );
        while( !travelStk.empty() ) {
            TreeNode* now = travelStk.top();
            travelStk.pop();
            if( now != NULL ) {
                if( now->right != NULL || now->left != NULL ) {
                    travelStk.push( now->right );
                    now->right = NULL;
                    travelStk.push( now );
                    travelStk.push( now->left );
                    now->left = NULL;
                } else {
                    ret.push_back( now->val );
                }
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