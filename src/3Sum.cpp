class Solution 
{
private:
	bool binarySearch(int left, int right, int dest, vector<int>& nums) 
	{
		int mid = left + ( (right - left) >> 1);
		while (left + 1 < right) 
		{
			if (nums[mid] == dest) 
			{
				return true;
			}
			else if (nums[mid] > dest) 
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
			mid = left + ( (right - left) >> 1);
		}
		if (nums[left] == dest)
		{
			return true;
		}
		if (nums[mid] == dest)
		{
			return true;
		}
		return nums[right] == dest;
	}

public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int i = 0; i < ( int )nums.size() - 2; ++i) 
		{
			if (i > 0 && nums[i] == nums[i - 1]) 
			{
				continue;
			}
			for (int j = i + 1; j < (int)nums.size() - 1; ++j) 
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				int a = nums[i];
				int b = nums[j];
				if (j + 1 < nums.size() && this->binarySearch(j+1, nums.size() - 1 , 0 - a- b , nums ) ) 
				{
					vector<int> innerRet{ a,0 - a - b,b };
					ret.push_back(innerRet);
				}
			}
		}
		return ret;
	}
};
