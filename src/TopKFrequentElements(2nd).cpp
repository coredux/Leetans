typedef pair<int, int> pii;

class Solution
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		unordered_map<int, int> numMp;
		for (auto i = nums.begin(); i != nums.end(); ++i)
		{
			if (numMp.find(*i) == numMp.end())
			{
				numMp[*i] = 0;
			}
			++numMp[*i];
		}
		vector<pii> pv;
		for (auto i = numMp.begin(); i != numMp.end(); ++i)
		{
			pv.push_back(make_pair((*i).second, (*i).first));
		}
		sort(pv.begin(), pv.end(), [](const pii &a, const pii &b) -> bool { return a.first > b.first; });
		vector<int> ret;
		for (int i = 0; i < k; ++i)
		{
			ret.push_back(pv[i].second);
		}
		return ret;
	}
};
