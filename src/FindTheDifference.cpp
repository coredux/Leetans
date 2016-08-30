class Solution {
private:
    static const int LETTER_NUM = 26;
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> mp;
        for ( auto i = s.begin(); i != s.end(); ++i ) {
            int idx = *i - 'a';
            if ( mp.find( idx ) != mp.end() ) {
                mp[idx] += 1;
            } else {
                mp[idx] = 1;
            }
        }
        char ret = 'a';
        for ( auto i = t.begin(); i != t.end() ; ++i ) {
            int idx = *i - 'a';
            if ( mp.find( idx ) != mp.end() && mp[idx] > 0 ) {
                mp[idx] -= 1;
            } else {
                ret = *i;
                break;
            }
        }
        return ret;
    }
};
