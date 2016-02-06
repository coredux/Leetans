//
// Created by seanr on 2016/2/6.
//



#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// submit the codes blow

int maxOfTwo( int a , int b ) {
    return a > b ? a:b;
}

int maxDepth(struct TreeNode* root) {

    if( root == NULL ) {
        return 0;
    }
    return maxOfTwo( maxDepth( root->left ) , maxDepth( root->right ) ) + 1;

}


// submit the codes above

int main() {
    return 0;
}
