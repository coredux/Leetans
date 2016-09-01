class Solution {
private:
    vector<vector<int>> ret;
    void dfs( vector<int> pre , vector<bool> visit , int idx , vector<int>& num ) {
        unordered_map<int,int> mp;
        visit[idx] = true;
        pre.push_back(idx);
        bool remain = false;
        for ( int i = 0 ; i < num.size() ; ++i ) {
            if ( !visit[i] && mp.find(num[i]) == mp.end() ) {
                remain = true;
                mp[num[i]] = 1;
                dfs( pre , visit , i , num );
            }
        }
        if ( !remain ) {
            vector<int> tmpRet;
            for ( int i = 0 ; i < pre.size() ; ++i ) {
                tmpRet.push_back( num[pre[i]]);
            }
            this->ret.push_back(tmpRet);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            vector<bool> visit(nums.size(), false);
            vector<int> pre;
            if ( mp.find(nums[i]) == mp.end() ) {
                mp[nums[i]] = 1;
                dfs( pre , visit , i , nums );
            }
        }
        return this->ret;
    }
};
