#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for ( auto i = nums1.begin(); i != nums1.end() ; ++i ) {
            if ( mp.find( *i ) != mp.end() ) {
                mp[ *i ] += 1;
            } else {
                mp.insert( { *i , 1 } );
            }
        }
        vector<int> ret;
        for ( auto i = nums2.begin() ; i != nums2.end() ; ++i ) {
            if ( mp.find( *i ) != mp.end() && mp[ *i ] > 0 ) {
                ret.push_back( *i );
                mp[ *i ] -= 1;
            }
        }
        return ret;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}