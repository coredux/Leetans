class Solution {
private:
    int binarySearch( vector<int>& nums , int left ,int right , int target ) {

        int mid = right - ( right - left ) / 2;

        while ( left + 1 < right ) {
            if ( nums[mid] == target ) {
                return mid;
            }
            if ( nums[mid] > nums[left] ) {
                if ( nums[mid] > target ) {
                    int re = this->binarySearch( nums, left, mid , target );
                    if ( re != -1 ) {
                        return re;
                    } else {
                        return this->binarySearch( nums, mid , right , target );
                    }
                } else {
                    left = mid;
                }
            } else {
                if ( nums[mid] > target ) {
                    right = mid;
                } else {
                    int re1 = this->binarySearch( nums , left , mid , target );
                    if ( re1 != -1 ) {
                        return re1;
                    } else {
                        return this->binarySearch( nums, mid , right , target );
                    }
                }
            }
            mid = right - ( right - left ) / 2;
        }
        if ( nums[left] == target ) {
            return left;
        }
        if ( nums[right] == target ) {
            return right;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        return this->binarySearch( nums , 0 , nums.size() - 1 , target );
    }
};
