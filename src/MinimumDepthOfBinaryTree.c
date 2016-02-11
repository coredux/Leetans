//
// Created by seanr on 2016/2/11.
//

#include <stddef.h>

struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
};

// submit the codes below

int minOfTwo( int a , int b ) {
    return a<b?a:b;
}

int minDepth(struct TreeNode* root) {

    if( root == NULL ) {
        return 0;
    }
    if( root->left != NULL && root->right != NULL ) {
        return minOfTwo( minDepth( root->left ) , minDepth( root->right ) ) + 1;
    } else if ( root->left != NULL && root->right == NULL ) {
        return minDepth( root->left ) + 1;
    } else {
        return minDepth( root->right ) + 1;
    }

}

// submit the codes above

int main() {
    return 0;
}
