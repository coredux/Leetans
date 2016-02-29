#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ret = 0;
        int cnt = 1;
        for ( std::vector<int>::iterator i = nums.begin() ; i != nums.end() ; ++i ) {
            ret = ret ^ cnt ^ (*i);
            ++cnt;
        }
        return ret;
    }
};

// submit the codes above

int main() {
    Solution s;
    vector<int> v{0,1};
    cout << s.missingNumber( v ) << endl;
    return 0;
}