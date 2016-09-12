class Solution {
private:
    int findPairPos ( string& str , int pos ) {
        if ( pos < str.length() && * ( str.cbegin() + pos ) == '[' ) {
            int left = 0;
            int right = 0;
            int retPos = pos;
            for ( auto i = str.cbegin() + pos ; i != str.cend(); ++i,++retPos ) {
                if ( *i == '[') {
                    ++left;
                } else if ( *i == ']' ) {
                    ++right;
                }
                if ( left == right ) {
                    return retPos;
                }
            }
            return -1;
        } else {
            return -1;
        }
    }

    int findRepeatTimes( string& str , int pos , int& startPos ) {
        if ( pos < str.length() && * ( str.cbegin() + pos ) == '[' ) {
            auto idx = str.cbegin() + pos - 1;
            while ( idx >= str.cbegin() ) {
                if ( ! (*idx >= '0' && *idx <= '9') ) {
                    break;
                }
                --idx;
            }
            string::const_iterator numIter;
            if ( idx >= str.cbegin() ) {
                numIter = idx + 1;
                startPos = numIter - str.cbegin() ;
            } else {
                numIter = str.cbegin();
                startPos = 0;
            }
            int ret = 0;
            for ( auto i = numIter ; i != str.cbegin() + pos ; ++i ) {
                ret *= 10;
                ret += ( *i - '0' );
            }
            return ret;
        } else {
            return -1;
        }
    }
public:
    string decodeString(string s) {
        string retStr = s;
        int nowLeft = -1;
        while ( ( nowLeft = retStr.find_first_of('[') ) != string::npos ) {
            int nowRight = this->findPairPos( retStr , nowLeft );
            int leftEdge = 0;
            int repeatTimes = this->findRepeatTimes( retStr , nowLeft , leftEdge );
            int delta = nowRight - leftEdge;
            string subStr = retStr.substr( nowLeft + 1 , nowRight - nowLeft - 1 );
            string newStr  = "";
            for ( int i = 0; i < repeatTimes; ++i ) {
                newStr += subStr;
            }
            retStr.replace( leftEdge , nowRight - leftEdge + 1 , newStr );
        }
        return retStr;
    }
};
