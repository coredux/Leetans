//
// Created by seanr on 2016/2/8.
//

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


// submit the codes below

int getHeight(struct TreeNode* root ) {
    if( root == NULL ) {
        return 0;
    }
    int leftHeight = getHeight( root->left );
    int rightHeight = getHeight( root->right );
    if( leftHeight == -1 || rightHeight == -1 || abs( leftHeight - rightHeight ) > 1 ) {
        return -1;
    } else {
        return leftHeight>rightHeight?leftHeight+1:rightHeight+1;
    }
}

bool isBalanced(struct TreeNode* root) {

    if( getHeight( root ) == -1 ) {
        return false;
    }
    return true;

}

// submit the codes above


int main() {
    return 0;
}

