#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    string intToRoman(int num) {

        string ret = string("");
        int thouNum = num / 1000;
        if( thouNum > 0 && thouNum < 4 ) {
            ret += thouTable[ thouNum - 1 ];
            num = num - thouNum * 1000;
        }
        int hundNum = num / 100;
        if( hundNum > 0 && hundNum < 10 ) {
            ret += hundTable[ hundNum - 1 ];
            num = num - hundNum * 100;
        }
        int tensNum = num / 10;
        if( tensNum > 0 && tensNum < 10 ) {
            ret += tensTable[ tensNum - 1 ];
            num =  num - tensNum * 10;
        }

        if( num > 0 && num < 10 ) {
            ret += unitsTable[ num - 1 ];
        }

        return ret;

    }
    const static vector<string> unitsTable;
    const static vector<string> tensTable;
    const static vector<string> hundTable;
    const static vector<string> thouTable;
};

const vector<string> Solution::unitsTable = { "I", "II", "III", "IV", "V",
                                              "VI", "VII", "VIII", "IX" };
const vector<string> Solution::tensTable = {  "X", "XX", "XXX", "XL", "L",
                                              "LX", "LXX", "LXXX", "XC"};
const vector<string> Solution::hundTable = { "C", "CC", "CCC", "CD", "D",
                                             "DC", "DCC", "DCCC", "CM"};
const vector<string> Solution::thouTable = { "M","MM","MMM" };

// submit the codes above

int main() {
    Solution s;
    cout << s.intToRoman( 10 ) << endl;
    return 0;
}