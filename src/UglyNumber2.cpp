
class Solution {

public:
    int nthUglyNumber(int n) {
        vector<int> container;
        container.push_back(1);
        int idx1, idx2, idx3;
        idx1 = idx2 = idx3 = 0;
        int cnt = 1;
        while ( cnt != n ) {
            container.push_back( min( container[idx1] * 2 , min ( container[idx2] * 3 , container[idx3] * 5 ) ) );
            if ( container.back() == container[idx1] * 2 ) {
                ++idx1;
            }
            if ( container.back() == container[idx2] * 3 ) {
                ++idx2;
            }
            if ( container.back() == container[idx3] * 5 ) {
                ++idx3;
            }
            ++cnt;
        }
        return  container.back();
    }
};
