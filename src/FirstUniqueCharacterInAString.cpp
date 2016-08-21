#include <iostream>
#include <vector>

using namespace std;

// submit the codes below
class Solution {
private:

    static const int LETTER_NUM = 30;

public:
    int firstUniqChar(string s) {
        vector<int> showTime( LETTER_NUM , 0 );
        vector<int> firstAppearIndex( LETTER_NUM , -1 );

        int idx = 0;
        for ( auto i = s.begin(); i != s.end(); ++i ) {
            char ch = *i;
            ++showTime[ ch - 'a' ];
            if ( firstAppearIndex[ ch - 'a'] == -1 ) {
                firstAppearIndex[ ch - 'a' ] = idx;
            }
            ++idx;
        }

        int minIdx = s.length() - 1;
        bool found = false;

        for ( int i = 0 ; i < showTime.size(); ++i ) {
            if ( showTime[i] == 1 && minIdx >= firstAppearIndex[i] ) {
                minIdx = firstAppearIndex[i];
                found = true;
            }
        }

        if ( found ) {
            return minIdx;
        } else {
            return -1;
        }
    }
};


// submit the codes above

int main() {
    Solution s;
    string str = "l";
    cout << s.firstUniqChar(str) << endl;
    return 0;
}