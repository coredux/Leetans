#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// submit the codes below

bool myCmp( const int &a , const int &b ) {
    return a > b;
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort( citations.begin() , citations.end() , myCmp );
        int hVal = 0;
        for ( int i = 0 ; i < citations.size() ; ++i ) {
            if ( citations[i] >= i + 1 ) {
                ++hVal;
            }
        }
        return hVal;
    }
};

// submit the codes above

int main() {
    Solution s;
    vector<int> v = { 0 };
    cout << s.hIndex(v)  << endl;
    return 0;
}