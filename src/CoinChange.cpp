#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if ( amount < 0) {
            return -1;
        }
        if ( amount == 0 ) {
            return 0;
        }
        vector<int> dp( amount + 1 , -1 );
        dp[amount] = 0;

        for ( int v = amount ; v >= 0 ; --v ) {
            for ( int i = 0 ; i < coins.size() ; ++i ) {
                if ( v - coins[i] >= 0 && dp[v] != -1 ) {
                    if ( dp[v-coins[i]] != -1 ) {
                       dp[v-coins[i]] = min( dp[v-coins[i]] , dp[v] + 1 );
                    } else {
                       dp[v-coins[i]] = dp[v] + 1;
                    }
                }
            }
        }
        return dp[0];
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}