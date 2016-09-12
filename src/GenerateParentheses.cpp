class Solution {
private:
    vector<string> ret;

    void bfs( int left , int right , const string father , int n ) {
        if ( left == n ) {
            if ( right == n ) {
                this->ret.push_back( father );
                return ;
            } else {
                bfs( left , right + 1 , father + ")" , n );
            }
        } else {
            if ( left == right ) {
                bfs ( left + 1 , right , father + "(" , n );
            } else {
                bfs ( left + 1 , right , father + "(" , n );
                bfs ( left , right + 1 , father + ")" , n );
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        bfs( 0 , 0 , "" , n );
        return this->ret;
    }
};
