//
// Created by seanr on 2016/2/6.
//

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// submit the codes below

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    if( p == NULL && q == NULL ) {
        return true;
    }

    if( p == NULL || q == NULL || p->val != q->val ) {
        return false;
    }

    bool leftRet = isSameTree( p->left , q->left );

    if( !leftRet ) {
        return false;
    }

    bool rightRet = isSameTree( p->right , q->right );

    if( !rightRet ) {
        return false;
    }

    return true;

}

// submit the codes above

int main() {
    return 0;
}

