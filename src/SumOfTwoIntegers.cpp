#include <iostream>
#include <vector>

using namespace std;

// submit the codes below

class Solution {
public:
    const static int BITS_COUNT = 64;

    int getSum(int a, int b) {
        vector<int> vecA = this->int2vec(a);
        vector<int> vecB = this->int2vec(b);

        int idxA = 0;
        int idxB = 0;
        int flag = 0;
        vector<int> sumBits;
        while ( idxA < vecA.size() || idxB < vecB.size() || flag == 1 ) {
            int na = this->fetchBitNum( vecA , idxA );
            int nb = this->fetchBitNum( vecB , idxB );
            if ( na == 0 && nb == 0 ) {
                sumBits.push_back(flag);
                flag = 0;
            } else if ( na == 1 && nb == 1 ){
                sumBits.push_back(flag);
                flag = 1;
            } else {
                if ( flag  == 0 ) {
                    sumBits.push_back(1);
                } else {
                    sumBits.push_back(0);
                }
            }
            ++idxA;
            ++idxB;
        }
        return vec2int(sumBits);
    }

    int fetchBitNum( const vector<int>& from , int bit ) {
        if ( bit >= 0 && bit < from.size() ) {
            return from[bit];
        } else {
            return 0;
        }
    }

    int vec2int( vector<int>& a ) {
        unsigned int ret = 0;
        for ( int i = a.size() - 1 ; i >= 0 ; --i ) {
            ret = ret << 1;
            ret = ret | a[i];
        }
        return static_cast<int>(ret);
    }

    vector<int> int2vec( int a ) {
        unsigned int x = static_cast<unsigned int>(a);
        vector<int> ret( BITS_COUNT , 0 );
        int idx = 0;
        while( x != 0 && idx < BITS_COUNT  ) {
            ret[idx] = x & 1;
            x = x >> 1;
            ++idx;
        }
        return ret;
    }

};

// submit the codes above

int main() {
    Solution s;
    cout << s.getSum( 1000 , -299 ) << endl;
    return 0;
}