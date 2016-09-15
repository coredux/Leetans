
class Solution {
private:
    void crossLink( TreeLinkNode *leftRoot , TreeLinkNode *rightRoot ) {
        if ( leftRoot != NULL && rightRoot != NULL && leftRoot->right != NULL  ) {
            leftRoot->right->next = rightRoot->left;
            crossLink( leftRoot->right , rightRoot->left );
        }
    }

    void directChildrenLink( TreeLinkNode* root ) {
        if ( root == NULL ) {
            return;
        }
        if ( root->left != NULL ) {
            root->left->next = root->right;
        }
        directChildrenLink( root->left );
        directChildrenLink( root->right );
        crossLink( root->left , root->right );
    }

public:
    void connect(TreeLinkNode *root) {
        directChildrenLink(root);
    }
};
