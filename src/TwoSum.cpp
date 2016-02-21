#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// submit the codes below

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map< int , int > mp;
        vector< int > ret;

        for( int i = 0 ; i < nums.size(); ++i ) {
            mp[ nums[ i ] ] = i;
        }

        for( int i = 0 ; i < nums.size(); ++i ) {
            int dest = target - nums[ i ];
            if( mp.find( dest ) != mp.end() && i != mp[ dest ] ) {
                ret.push_back( i );
                ret.push_back( mp[ dest ] );
                break;
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