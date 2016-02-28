#include <iostream>
#include <unordered_map>

using namespace std;


// submit the codes below

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        unordered_map<char,int> parent;
        for ( auto ch : A ) {
            if ( parent.find(ch) != parent.end() ) {
                ++parent[ ch ];
            } else {
                parent[ ch ] = 1;
            }
        }
        for ( auto ch : B ) {
            if ( parent.find(ch) == parent.end() || parent[ ch ] < 1 ) {
                return false;
            } else {
                --parent[ ch ];
            }
        }
        return true;

    }
};


// submit the codes above

int main() {
    Solution s;
    cout << s.compareStrings( "ABCD" , "ABC") << endl;
    return 0;
}