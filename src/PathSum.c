//
// Created by seanr on 2016/2/11.
//

#include <stdbool.h>
#include <stddef.h>

struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

// submit the codes below

bool hasPathSum(struct TreeNode* root, int sum) {

    if( root == NULL ) {
        return false;
    }
    if( root->left == NULL && root->right == NULL && root->val == sum ) {
        return true;
    }
    return hasPathSum( root->left , sum - root->val ) || hasPathSum( root->right , sum - root->val );

}

// submit the codes above

int main() {
    return 0;
}

