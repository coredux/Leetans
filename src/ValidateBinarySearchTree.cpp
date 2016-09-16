class Solution {
private:
    bool validate( TreeNode* root, vector<int> greater, vector<int> less ) {
        if ( root == NULL ) {
            return true;
        }
        for ( auto i = greater.cbegin(); i != greater.cend(); ++i ) {
            if ( *i >= root->val ) {
                return false;
            }
        }
        for ( auto i = less.cbegin(); i != less.cend(); ++i ) {
            if ( *i <= root->val ) {
                return false;
            }
        }
        vector<int> newGreater(greater);
        newGreater.push_back(root->val);
        vector<int> newLess(less);
        newLess.push_back(root->val);
        return validate( root->left , greater , newLess ) && validate( root->right , newGreater , less );
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate( root , vector<int>() , vector<int>() );
    }
};
