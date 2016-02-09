//
// Created by seanr on 2016/2/8.
//

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// submit the codes below

bool cmpTree(struct TreeNode* t1 , struct TreeNode* t2 ) {

    if( t1 == NULL && t2 == NULL ) {
        return true;
    }
    if( t1 != NULL && t2 != NULL && t1->val == t2->val ) {
        return cmpTree( t1->left , t2->right ) && cmpTree( t1->right , t2->left );
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if( root == NULL ) {
        return true;
    }
    return cmpTree( root->left , root->right );
}

// submit the codes above

int main() {
    return 0;
}

