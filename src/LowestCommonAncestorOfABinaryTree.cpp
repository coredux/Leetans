
class Solution
{
private:
	bool dfs(TreeNode* root, TreeNode* dest, vector<int>& path )
	{
		if (root == NULL)
		{
			return false;
		}
		if (root == dest)
		{
			return true;
		}
		else if ( root->left != NULL && dfs(root->left, dest, path))
		{
			path.push_back(-1);
			return true;
		}
		else if ( root->right != NULL && dfs(root->right, dest, path) )
		{
			path.push_back(1);
			return true;
		}
		return false;
	}

	TreeNode* findByPath(TreeNode* root, vector<int> path)
	{
		TreeNode* now = root;
		for (auto i = path.begin(); i != path.end() && now != NULL; ++i)
		{
			if (*i > 0)
			{
				now = now->right;
			}
			else if (*i < 0)
			{
				now = now->left;
			}
		}
		return now;
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		vector<int> pPath;
		vector<int> qPath; 
		if (dfs(root, p, pPath) && dfs(root, q, qPath))
		{
			reverse(pPath.begin(), pPath.end());
			reverse(qPath.begin(), qPath.end());
			vector<int> path;
			auto iterP = pPath.begin();
			auto iterQ = qPath.begin();
			while (iterP != pPath.end() && iterQ != qPath.end() && *iterP == *iterQ)
			{
				path.push_back(*iterP);
				++iterP;
				++iterQ;
			}
			return this->findByPath(root, path);
		}
		else
		{
			return NULL;
		}
	}
};
