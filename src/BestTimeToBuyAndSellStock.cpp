#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// submit the codes below

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() < 2 ) {
            return 0;
        }
        int pre = *prices.begin();
        int tmp = 0;
        for (auto i = prices.begin() ; i != prices.end(); ++i ) {
            tmp = *i;
            *i = *i - pre;
            pre = tmp;
        }
        vector<int> dp( prices.size() , 0 );
        int maxProfit = 0;
        for ( auto i = dp.begin() + 1 ; i != dp.end() ; ++i ) {
            int priceAti = prices.at( i - dp.begin() );
            *i = max( priceAti , *( i - 1 ) + priceAti );
            if ( *i > maxProfit ) {
                maxProfit = *i;
            }
        }
        return maxProfit;
    }
};

// submit the codes above

int main() {
    vector<int> a = { 3 , 2 , 1 ,4 ,5 ,7 , 2 ,3 };
    a = {};
    Solution s;
    cout << s.maxProfit( a ) << endl;
    return 0;
}