
class Solution {
private:
    void reverse( vector<int>& nums , int start ) {
        if ( start >= 0 && start < nums.size() ) {
            int idxFront = start;
            int idxEnd = nums.size() - 1;
            while ( idxFront < idxEnd ) {
                swap( nums[idxFront] , nums[idxEnd]);
                ++idxFront;
                --idxEnd;
            }
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        bool found = false;
        for ( int i = nums.size() - 1 ; i > 0 ; --i ) {
            if ( nums[i] > nums[i-1] ) {
                found = true;
                int toRepIdx = i -1;
                int toSwapIdx = -1;
                for ( int j = nums.size() - 1; j > toRepIdx; --j ) {
                    if ( nums[j] > nums[toRepIdx]) {
                        toSwapIdx = j;
                        break;
                    }
                }
                if ( toSwapIdx != - 1 ) {
                    swap( nums[toRepIdx] , nums[toSwapIdx] );
                    this->reverse( nums , toRepIdx + 1 );
                }
                break;
            }
        }
        if ( !found ) {
            this->reverse( nums , 0 );
        }

    }
};
