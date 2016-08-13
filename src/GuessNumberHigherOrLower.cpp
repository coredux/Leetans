#include <iostream>

using namespace std;

int myNum = 0;
int guess(int num);

// submit the codes below

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int mid = n;
        int right = n;
        while ( guess(mid) != 0 ) {
            if ( guess(mid) > 0 ) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = left + ( right - left ) / 2;
        }
        return mid;
    }
};

// submit the codes above

int guess( int num ) {
    if ( myNum > num ) {
        return 1;
    } else if ( myNum < num ) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    myNum = 6;
    Solution s;
    cout << s.guessNumber( 10 ) << endl;
    return 0;
}