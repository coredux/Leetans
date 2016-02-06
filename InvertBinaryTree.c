//
// Created by seanr on 2016/2/6.
//
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// submit the codes below

struct TreeNode* invertTree(struct TreeNode* root) {

    if( root == NULL ) {
        return NULL;
    }

    root->left = invertTree( root->left );
    root->right = invertTree( root->right );

    struct TreeNode* temp = root->left;

    root->left = root->right;
    root->right = temp;

    return root;

}

// submit the codes above

int main() {
    return 0;
}

