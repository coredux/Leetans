#include <iostream>
#include <unordered_map>

using namespace std;

// submit the codes below

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;

        for( auto ch : s ) {
            if ( sMap.find( ch ) != sMap.end() ) {
                ++sMap[ ch ];
            } else {
                sMap[ ch ] = 1;
            }
        }
        for( auto ch : t ) {
            if ( tMap.find( ch ) != tMap.end() ) {
                ++tMap[ ch ];
            } else {
                tMap[ ch ] = 1;
            }
        }

        return sMap == tMap;

    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.anagram( "abcd" , "dcba" )<< endl;
    return 0;
}