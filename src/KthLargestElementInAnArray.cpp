class Solution
{
public:
	int findKthLargest(vector<int>&nums, int k)
	{
		return PartionSearch(nums, k, 0, nums.size());
	}

	int PartionSearch(vector<int>& nums, int k , int _idxFront , int _idxEnd)
	{
		int pivot = nums[_idxFront];
		int bigger = 0;
		int idxFront = _idxFront + 1;
		int idxEnd = _idxEnd - 1;
		while (idxFront <= idxEnd)
		{
			while ( idxFront <= idxEnd && nums[idxFront] >= pivot)
			{
				++bigger;
				++idxFront;
			}
			while ( idxFront <= idxEnd && nums[idxEnd] < pivot)
			{
				--idxEnd;
			}
			if (idxFront < idxEnd)
			{
				int tmp = nums[idxFront];
				nums[idxFront] = nums[idxEnd];
				nums[idxEnd] = tmp;
				++bigger;
				++idxFront;
				--idxEnd;
			}
		}
		if (bigger == k - 1)
		{
			return pivot;
		}
		if (bigger > k - 1)
		{
			return PartionSearch(nums, k, _idxFront + 1, idxFront);
		}
		else
		{
			return PartionSearch(nums, k - bigger - 1, idxFront, _idxEnd);
		}
	}
};
