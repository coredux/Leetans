
class Solution {
private:
    void clearPreviousRecord( int pos , unordered_map<int,int>& mp ) {
        for ( auto i = mp.begin(); i != mp.end() ; ++i ) {
            if ( i->second <= pos ) {
                i->second = -1;
            }
        }
    }
public:
    int lengthOfLongestSubstring(string s) {
        if ( s.length() < 1 ) {
            return 0;
        }
        vector<int> dp( s.length() + 1 , -1 );
        unordered_map<int,int> mp;

        const char* ps = s.c_str();
        int maxLen = 1;

        dp[0] = 1;
        mp[ps[0]] = 0;

        for ( int i = 1; i < s.length() ; ++i ) {
            if ( mp.find( ps[i] ) == mp.end() || mp[ps[i]] == -1 ) {
                mp[ps[i]] = i;
                dp[i] = dp[i-1] + 1;
            } else {
                int lastPos = mp[ps[i]];
                dp[i] = max( i - lastPos , 1 );
                this->clearPreviousRecord( lastPos , mp );
                mp[ps[i]] = i;
            }
            if ( maxLen < dp[i] ) {
                maxLen = dp[i];
            }
        }
        return maxLen;
    }
};
