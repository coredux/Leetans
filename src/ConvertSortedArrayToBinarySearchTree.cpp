#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode( int x ): val( x ) , left( NULL ) , right( NULL ) {}
};

// submit the codes below

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *ret = nullptr;
        return makeBST( nums , ret );
    }

private:
    TreeNode* makeBST( vector<int>& nums , TreeNode* root ) {
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.end();
        if( left == right ) {
            return nullptr;
        }
        vector<int>::iterator mid = left + ( right - left ) / 2;
        root = new TreeNode( *mid );
        vector<int> leftNum( nums.begin() , mid );
        root->left = makeBST( leftNum , root->left );
        if ( mid + 1 != nums.end() ) {
            vector<int> rightNum( mid + 1 , nums.end() );
            root->right = makeBST( rightNum , root->right );
        }
        return root;

    }
};

// submit the codes above

int main() {
    Solution s;
    vector<int> v = { 0 };
    s.sortedArrayToBST( v );
    cout << "Hello, World!" << endl;
    return 0;
}