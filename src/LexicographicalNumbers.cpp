#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;


class SolutionSlow {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        if ( n < 1 ) {
            return ret;
        }
        Trie* head = new Trie();

        for ( int i = 1 ; i <= n ; ++i ) {
            string nowNum = this->int2string(i);
            head->insert(nowNum);
        }

        string s;
        head->travel( ret , s );
        releaseTrie(head);
        return ret;
    }

    static string int2string( int num ) {
        stringstream stream;
        stream<<num;
        return stream.str();
    }
    static int string2int( string num ) {
        const char* str = num.c_str();
        int ret = 0;
        while ( *str != '\0'  ) {
            ret = ret * 10;
            ret += ( *str - '0' );
            str++;
        }
        return ret;
    }

private:

    static const int MAX_NUM_BIT = 10;

   struct Trie {

        Trie* children[MAX_NUM_BIT];

        Trie() {
            for ( int i = 0 ; i < MAX_NUM_BIT ; ++i ) {
                this->children[i] = NULL;
            }
        }


        void insert( string num ) {
            if ( num.length() == 0 ) {
                return;
            }
            int nowNumIdx = num.c_str()[0] - '0';
            if ( this->children[nowNumIdx] == NULL ) {
                this->children[nowNumIdx] = new Trie();
            }

            if ( num.length() > 1 ) {
                string last( &num.c_str()[1] );
                this->children[nowNumIdx]->insert(last);
            }
        }

        void travel(  vector<int>& container , string parent ) {
            for ( int i = 0 ; i < MAX_NUM_BIT ; ++i ) {
                if ( this->children[i] != NULL ) {
                    container.push_back( string2int( parent + int2string(i) ) );
                    this->children[i]->travel( container , parent + int2string(i));
                }
            }
        }

    };

    void releaseTrie( Trie* head ) {
        if ( head == NULL ) {
            return;
        }
        for ( int i = 0 ; i < MAX_NUM_BIT ; ++i ) {
            if ( head->children[i] != NULL ) {
                releaseTrie(head->children[i]);
                head->children[i] = NULL;
            }
        }
        delete(head);
        return;
    }


};


class SolutionVerySlow {

public:

    static bool cmp( int a , int b );


    static string int2string( int num ) {
        stringstream stream;
        stream<<num;
        return stream.str();
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ret( n , 0 );
        for ( int i = 1 ; i <= n ; ++i ) {
            ret[i-1] = i;
        }
        sort( ret.begin(), ret.end() , SolutionVerySlow::cmp );
        return ret;
    }

};

bool SolutionVerySlow::cmp(int a, int b ) {
    return SolutionVerySlow::int2string(a).compare( SolutionVerySlow::int2string(b) ) < 0;
}

// submit the codes below

class Solution {

public:

    int edge;

    vector<int> lexicalOrder(int n) {
        vector<int> ret;

        if ( n < 1 ) {
            return ret;
        }
        this->edge = n;

        for ( int i = 1 ; i < 10 && i <= n ; ++i ) {
            dfs( ret , i );
        }
        return ret;
    }

    void dfs ( vector<int>& que , int num ) {

        if ( num <= this->edge ) {
            que.push_back(num);
        } else {
            return;
        }
        for ( int i = 0 ; i < 10 ; ++i ) {
            dfs( que, num*10 + i );
        }

    }

};


// submit the codes above

int main() {
    Solution s;
    vector<int> ret = s.lexicalOrder(13);
    for ( int i = 0 ; i < ret.size(); ++i ) {
        cout << ret[i] << endl;
    }
    return 0;
}