#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        this->generateDeltaVector( prices );
        int maxProfitVal = 0;
        for ( auto i = prices.begin() ; i != prices.end(); ++i ) {
            int tmp = maxProfitVal + *i;
            if ( tmp > maxProfitVal ) {
                maxProfitVal = tmp;
            }
        }
        return maxProfitVal;
    }

private:
    void generateDeltaVector( vector<int>& prices ) {
        if ( prices.size() < 1 ) {
            return ;
        }
        int tmp;
        int pre = *prices.begin();
        for ( int i = 0 ; i < prices.size() ; ++i ) {
            int tmp = prices[i];
            prices[i] = prices[i] - pre;
            pre = tmp;
        }
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}