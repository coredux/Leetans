class Solution {
private:
    int retrieve( int idx , vector<int>& vals ) {
        if ( idx >= 0 && idx < vals.size() ) {
            return vals[idx];
        } else {
            return 0;
        }
    }

public:
    int maxProfit(vector<int>& prices) {

        vector<int> sell( prices.size() + 1 , 0 );
        vector<int> buy( prices.size() + 1 , 0 );

        int ret = 0;

        if ( prices.size() < 2 ) {
            return 0;
        }

        buy[0] = -prices[0];
        for ( int i = 1 ; i < prices.size() ; ++i ) {
            buy[i] = max( this->retrieve( i - 2 , sell ) - prices[i] , this->retrieve( i - 1 , buy ) );
            sell[i] = max( this->retrieve( i - 1 , buy ) + prices[i] , this->retrieve( i - 1 , sell ));
            ret = max( ret , max( buy[i] , sell[i]) );
        }

        return ret;

    }
};
