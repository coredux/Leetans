#include <iostream>
#include <cstring>

using namespace std;

// submit the codes below

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if( source == nullptr || target == nullptr ) {
            return -1;
        }
        int  targetLen = strlen( target );
        if( targetLen == 0 ) {
            return 0;
        }
        int *next = new int[ targetLen ];
        next[ 0 ] = -1;

        int slowPos = -1;
        int fastPos = 0;
        while ( fastPos < targetLen ) {
            if ( slowPos == -1 || *( target + slowPos ) == *( target + fastPos ) ) {
                ++slowPos;
                ++fastPos;
                next[ fastPos ] = slowPos;
            } else {
                slowPos = next[ slowPos ];
            }
        }

        int sourceLen = strlen( source );

        int srcPos = 0;
        int tarPos = 0;
        while ( srcPos < sourceLen ) {
            if ( tarPos == -1 || *( source + srcPos ) == *( target + tarPos ) ) {
                ++srcPos;
                ++tarPos;
            } else {
                tarPos = next[ tarPos ];
            }
            if( tarPos == targetLen ) {
                delete(next);
                return srcPos - targetLen;
            }
        }
        delete(next);
        return -1;
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.strStr( "source" , "target" ) << endl;
    return 0;
}