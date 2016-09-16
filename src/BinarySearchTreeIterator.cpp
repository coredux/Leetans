class BSTIterator {
private:
    stack<TreeNode*> iterStk;

    void pushInStack( TreeNode* root ) {
        while ( root != NULL ) {
            iterStk.push( root );
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root) {
        this->pushInStack(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { // o(h)
        return !iterStk.empty();
    }

    /** @return the next smallest number */
    int next() { // o(1)
        TreeNode* top = iterStk.top();
        iterStk.pop();
        if ( top->right != NULL ) {
            this->pushInStack( top->right );
        }
        return top->val;
    }
};
