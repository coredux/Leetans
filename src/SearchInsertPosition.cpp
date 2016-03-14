#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator left = nums.begin();
        vector<int>::iterator right = nums.end() - 1;
        vector<int>::iterator mid = left + ( right - left ) / 2;
        while ( left <= right ) {
            if ( *mid < target ) {
                left = mid + 1;
            } else if ( *mid > target ) {
                right = mid - 1;
            } else {
                return ( mid - nums.begin() );
            }
            mid = left + ( right - left ) / 2;
        }
        return ( left - nums.begin() );


    }
};

// submit the codes above

int main() {
    vector<int> nums = { 1 , 3 , 5 , 6 };
    Solution s;
    cout << s.searchInsert( nums , 0 )<< endl;
    return 0;
}