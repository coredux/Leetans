#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet;
        for ( auto i = nums1.begin() ; i != nums1.end() ; ++i ) {
            numSet.insert( *i );
        }
        unordered_set<int> retSet;
        for ( auto i = nums2.begin() ; i != nums2.end() ; ++i ) {
            if ( numSet.find( *i ) != numSet.end() && retSet.find( *i ) == retSet.end() ) {
                retSet.insert( *i );
            }
        }
        vector<int> ret;
        for ( auto i = retSet.begin() ; i != retSet.end() ; ++i ) {
            ret.push_back( *i );
        }
        return ret;
    }
};

// submit the codes above

int main() {
    vector<int> nums1 = { 2 , 3 ,4 , 5 , 6};
    vector<int> nums2 = { 2 , 2 , 3 ,4 , 5 };
    return 0;
}