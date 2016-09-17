class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> idxes( primes.size() , 0 );
        vector<int> container;
        container.push_back(1);
        for ( int i = 1; i < n; ++i ) {
            int minIdx = -1;
            int minNum = INT32_MAX;
            for ( int j = 0; j < idxes.size(); ++j ) {
                int tmp = container[idxes[j]] * primes[j];
                if ( minNum > tmp && tmp != container.back() ) {
                    minNum = tmp;
                    minIdx = j;
                }
            }
            if ( minIdx != -1 ) {
                for ( int j = 0; j < idxes.size(); ++j ) {
                    int tmp = container[idxes[j]] * primes[j];
                    if ( tmp == minNum ) {
                        ++idxes[j];
                    }
                }
                container.push_back(minNum);
            }
        }
        return container.back();
    }
};
