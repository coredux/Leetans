class Solution {
private:
    int getSum( vector<int>& nums ) {
        int sum = 0;
        for ( auto i = nums.begin(); i != nums.end(); ++i ) {
            sum += *i;
        }
        return sum;
    }

    int getSequenceRet( vector<int>& nums , int start , int n ) {
        int ret = 0;
        for ( int i = 0 ; i < n ; ++i ) {
            if ( start + i < nums.size() ) {
                ret += i * nums[i + start];
            }
        }
        return ret;
    }
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = this->getSum(A);
        int n = A.size();
        vector<int> extended;
        extended.reserve( n + n );
        extended.insert( extended.end() , A.begin() , A.end() );
        extended.insert( extended.end() , A.begin() , A.end() );
        int ret = this->getSequenceRet( extended , 0 , n );
        int pre = ret;
        for ( int i = 1 ; i < n ; ++i ) {
            pre += n * extended[i-1] - sum;
            if ( pre > ret ) {
                ret = pre;
            }
        }
        return ret;
    }
};
