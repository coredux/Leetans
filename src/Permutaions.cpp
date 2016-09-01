class Solution {
private:
    vector<vector<int>> ret;
    void dfs( int idx, vector<int> pre, vector<bool> visit, vector<int>& num ) {
        visit[idx] = true;
        pre.push_back(idx);
        bool remain = false;
        for ( int i = 0 ; i < visit.size(); ++i ) {
            if ( !visit[i] ) {
                remain = true;
                dfs( i , pre , visit , num );
            }
        }
        if ( !remain ) {
            vector<int> tmpRet;
            for ( int i = 0 ; i < pre.size() ; ++i ) {
                tmpRet.push_back( num[pre[i]] );
            }
            this->ret.push_back(tmpRet);
        }

    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        for ( int i = 0 ; i < nums.size() ; ++i ) {
            vector<int> branch;
            vector<bool> visit( nums.size() , false );
            dfs( i , branch , visit , nums );
        }
        return this->ret;
    }
};
