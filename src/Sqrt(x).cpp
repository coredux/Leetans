class Solution {
private:

    bool isOverflow( int x ) {
        int mul = x * x;
        if ( mul < 0 ) {
            return true;
        }
        if ( mul / x != x ) {
            return true;
        }
        return false;
    }

public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int mid = left + ( right - left ) / 2;
        while ( left + 1 < right ) {
            if ( mid * mid == x ) {
                return mid;
            } else if ( mid * mid > x || this->isOverflow( mid ) ) {
                right = mid - 1;
            } else {
                left = mid;
            }
            mid = left + ( right - left ) / 2;
        }
        if ( right * right <= x ) {
            return right;
        }
        if ( mid * mid <= x ) {
            return mid;
        }
        return left;

    }
};
