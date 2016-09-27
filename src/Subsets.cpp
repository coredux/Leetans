
class Solution
{
private:
	void choose(vector<vector<int>>&container, vector<int>&nums, vector<bool> visit, vector<int> parent, int chooseSize, int idx)
	{
		if (chooseSize == 0)
		{
			container.push_back(parent);
			return;
		}
		if (idx >= 0 && idx < nums.size())
		{
			visit[idx] = true;
		}
		if (idx + chooseSize >= (int)nums.size())
		{
			return;
		}
		for (int i = idx + 1; i < nums.size(); ++i)
		{
			if (visit[i] == false)
			{
				vector<int> newParent(parent);
				newParent.push_back(nums[i]);
				choose(container, nums, visit, newParent, chooseSize - 1, i);
			}
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> ret;
		for (int i = 0; i <= nums.size(); ++i)
		{
			vector<bool> visit(nums.size(), false);
			vector<int> parent;
			this->choose(ret, nums, visit, parent, i, -1);
		}
		return ret;
	}
};
