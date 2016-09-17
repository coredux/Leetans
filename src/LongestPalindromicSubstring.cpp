
class Solution {
public:
    string longestPalindrome(string s) {
        if ( s.length() == 0 ) {
            return "";
        }
        vector<int> sVal( 2 * s.length() + 1 , -1 );
        vector<int> ratio( 2 * s.length() + 1 , 0 );
        int sValIdx = 1;
        for ( auto i = s.cbegin(); i != s.cend() ; ++i ) {
            sVal[sValIdx] = *i;
            sValIdx += 2;
        }

        int longestPalindromeCenter = 1;
        ratio[1] = 1;

        for ( int i = 1 ; i < sVal.size() ; ++i ) {
            if ( ratio[longestPalindromeCenter] + longestPalindromeCenter > i && 2*longestPalindromeCenter >= i ) {
                ratio[i] = min( ratio[longestPalindromeCenter] + longestPalindromeCenter - i,
                                ratio[2*longestPalindromeCenter - i]);
            } else {
                ratio[i] = 1;
            }

            while ( i - ratio[i] >= 0 &&
                    i + ratio[i] < sVal.size() &&
                    sVal[ i + ratio[i] ] == sVal[ i - ratio[i] ]) {
                ++ratio[i];
            }

            if ( ratio[i] > ratio[longestPalindromeCenter] ) {
                longestPalindromeCenter = i;
            }
        }

        int left = longestPalindromeCenter - ratio[longestPalindromeCenter] + 1;
        string ret = "";
        while ( left < longestPalindromeCenter + ratio[longestPalindromeCenter] ) {
            if ( sVal[left] >= 0 ) {
                ret += (char) sVal[left];
            }
            ++left;
        }
        return ret;
    }
};
