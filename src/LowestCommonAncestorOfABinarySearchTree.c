//
// Created by seanr on 2016/2/7.
//

#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


// submit the codes below

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    if( root == NULL || p == NULL || q == NULL ) {
        return NULL;
    }

    struct TreeNode* temp = p;
    if( p->val > q->val ) {
        p = q;
        q = temp;
    }
    if( p->val <= root->val && root->val <= q->val ) {
        return root;
    } else if ( p->val < root->val && q->val < root->val ) {
        return lowestCommonAncestor( root->left , p , q );
    } else {
        return lowestCommonAncestor( root->right , p , q );
    }

}

// submit the codes above

int main() {
    return 0;
}

