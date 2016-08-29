class Solution {
private:
    static const int MAX_SCALE = 10;
    int edge;
    vector<vector<int>> mem;
    int dfs( vector<bool> , int , int , int );
    int getEdge( int );

public :
    int countNumbersWithUniqueDigits(int n) {
        this->edge = this->getEdge(n);
        this->mem.assign( n + 1 , vector<int>( 10 , -1 ) );

        vector<bool> visit( 10 , false );
        int ret = dfs( visit , 0 , 0 , 0 );


        return ret + 1;
    }
};

int Solution::dfs(vector<bool> visit , int parent , int idx, int depth ) {

    if ( parent > 0 ) {
        visit[idx] = true;
    }
    int thisDepth = 0;
    for ( int i = 0 ; i < MAX_SCALE ; ++i ) {
        if (  ( parent * 10 + i ) < this->edge && ( i > 0 || parent > 0 ) ) {
            if ( !visit[i] ) {
                if ( this->mem[depth][i] == -1 ) {
                    this->mem[depth][i] = dfs( visit , parent * 10 + i , i , depth + 1  ) + 1;
                }
                thisDepth += this->mem[depth][i];
            }
        }
    }
    return thisDepth;

}

int Solution::getEdge(int n ) {
    int ret = 1;
    for ( int i = 0 ; i < n ; ++i ) {
        ret *= 10;
    }
    return ret;
}
