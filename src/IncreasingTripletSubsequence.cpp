
class Solution {
private:

    int binarySearch( vector<int>& nums , int right , int dest ) {
        int left = 0;
        int mid = left + ( right - left ) / 2;
        while ( left + 1 < right ) {
            if ( nums[mid] < dest ) {
                left = mid;
            } else {
                right = mid - 1;
            }
            mid = left + ( right - left ) / 2;
        }
        if ( nums[right] < dest ) {
            return right;
        }
        if ( nums[mid] < dest ) {
            return mid;
        }
        if ( nums[left] < dest ) {
            return left;
        } else {
            return 0;
        }
    }

public:
    bool increasingTriplet(vector<int>& nums) {

        if ( nums.size() < 3 ) {
            return false;
        }

        vector<int> dp( nums.size() + 1 , 1 );
        vector<int> dp2( nums.size() + 1 , 0 );

        dp2[1] = nums[0];

        int lisLen = 1;
        for ( int i = 1 ; i < nums.size() ; ++i ) {

            if ( nums[i] < dp2[1] ) {
                dp2[1] = nums[i];
            } else if ( nums[i] > dp2[lisLen] ) {
                ++lisLen;
                dp2[lisLen] = nums[i];
                dp[i] = lisLen;
            } else {
                int k = this->binarySearch( dp2 , lisLen , nums[i] );
                dp2[k + 1] = nums[i];
                dp[i] = k + 1;
            }
            if ( dp[i] >= 3 ) {
                return true;
            }
        }

        return false;
    }
};
