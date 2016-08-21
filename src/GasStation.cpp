#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:

    int edge;

    int increaseIndex( int idx ) {
        if ( idx + 1 < this->edge ) {
            return idx + 1;
        } else {
            return 0;
        }
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        this->edge = gas.size();
        vector<bool> startPoint( gas.size() , false);

        int i = 0;
        while( i < gas.size() ) {
            if ( gas[i] < cost[i] ) {
                ++i;
                continue;
            }
            if ( startPoint[i] ) {
                ++i;
                continue;
            } else {
                startPoint[i] = true;
            }
            int cap = gas[i] - cost[i];
            int start = this->increaseIndex( i );
            while( start != i && cap >= 0 ) {
                cap = cap + gas[start] - cost[start];
                start = this->increaseIndex( start );
            }
            if ( start == i && cap >= 0 ) {
                return i;
            } else {
                i = start;
            }
        }
        return -1;
    }
};

// submit the codes above

int main() {
    vector<int> gas { 2, 4 };
    vector<int> cost {3, 4 };
    Solution s;
    cout << s.canCompleteCircuit(gas,cost)<< endl;
    return 0;
}