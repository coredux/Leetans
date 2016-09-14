class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        for ( auto i = nums.begin() ; i != nums.end() ; ++i ) {
            if ( *i == 0 ) { zeros++; }
            else if ( *i == 1 ) { ones++; }
            else { twos++; }
        }
        for ( auto i = nums.begin(); i != nums.end(); ++i ) {
            if ( zeros > 0 ) { *i = 0; zeros--; }
            else if ( ones > 0 ) { *i = 1; ones--; }
            else if ( twos > 0 ) { *i = 2; twos--; }
        }
    }
};
