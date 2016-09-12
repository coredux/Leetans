class Solution {

private:

    int findFirstBiggerThan( vector<int>& nums , int dest ) {
        if ( nums.size() == 0 || nums.back() <= dest ) {
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + ( right - left ) / 2;
        while ( left + 1 < right ) {
            mid = left + ( right - left ) / 2;
            if ( nums[mid] <= dest ) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if ( nums[left] > dest ) {
            return nums[left];
        }
        if ( nums[mid] > dest ) {
            return nums[mid];
        }
        if ( nums[right] > dest ) {
            return nums[right];
        } else {
            return -1;
        }
    }

public:

    static const int LEETER_CNT = 30;

    bool isSubsequence(string s, string t) {
        vector<int> table[ LEETER_CNT ];
        int pos = 0;
        for ( auto i = t.cbegin(); i != t.cend(); ++i ) {
            char ch = *i;
            int idx = ch - 'a';
            if ( idx >= 0 && idx < LEETER_CNT ) {
                table[idx].push_back( pos++ );
            } else {
                return false;
            }
        }

        pos = -1;
        for ( auto i = s.cbegin(); i != s.cend() ; ++i ) {
            char ch = *i;
            int idx = ch - 'a';
            if ( idx >= 0 && idx < LEETER_CNT  ) {
                int firstBigger = this->findFirstBiggerThan( table[idx] , pos );
                if ( firstBigger == -1 ) { return false; }
                pos = firstBigger;
            } else { return false; }
        }
        return true;
    }
};
