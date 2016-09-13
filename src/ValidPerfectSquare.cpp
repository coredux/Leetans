
class Solution {
private:

    bool binarySearch( int dest ) {
        long long left = 0;
        long long right = dest;
        long long mid = left + ( right - left ) / 2;
        while ( left + 1 < right ) {
            if ( mid * mid == dest ) {
                return true;
            } else if ( mid * mid > dest ) {
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = left +  ( right - left ) / 2;
        }

        if ( left * left == dest ) {
            return true;
        }
        if ( mid * mid == dest ) {
            return true;
        }
        if ( right * right == dest ) {
            return true;
        }
        return false;
    }

public:
    bool isPerfectSquare(int num) {
        return this->binarySearch(num);
    }
};
