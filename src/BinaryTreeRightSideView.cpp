class Solution {
private:
    struct ValueNode {
        int val;
        int rank;
        ValueNode( int x , int rk) : val(x) , rank(rk) {}
    };
    vector<ValueNode> saved;
    void bfs( TreeNode* root , int rank ) {
        if ( root != NULL ) {
            this->saved.push_back(ValueNode(root->val, rank));
            if (root->right != NULL) {
                bfs(root->right, rank + 1);
            }
            if (root->left != NULL) {
                bfs(root->left, rank + 1);
            }
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        bfs( root , 0 );
        int nowDestRank = 0;
        vector<int> ret;
        for ( int i = 0; i < this->saved.size() ; ++i ) {
            ValueNode now = this->saved[i];
            if ( now.rank == nowDestRank ) {
                nowDestRank += 1;
                ret.push_back( now.val );
            }
        }
        return ret;
    }
};
