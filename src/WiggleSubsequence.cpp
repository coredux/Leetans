class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if ( nums.size() < 2 ) {
            return nums.size();
        }
        int incState = 0;
        int ret = 1;
        for ( int i = 1; i < nums.size() ; ++i ) {
            int nowNum = nums[i];
            int preNum = nums[i-1];
            if ( incState < 1 && nowNum > preNum ) {
                incState = 1;
                ++ret;
            } else if ( incState > -1 && nowNum < preNum ) {
                incState = -1;
                ++ret;
            }
        }
        return ret;
    }
};
