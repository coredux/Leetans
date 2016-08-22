#include <iostream>
#include <algorithm>

using namespace std;

// submit the codes below

class Solution {
private:
    string regularization( string s ) {
        auto slow = s.begin();
        auto fast = s.begin();


            // move fast to first word
            while( fast != s.end() && *fast == ' ' ) {
                ++fast;
            }

            // for each word
            while ( fast != s.end() ) {

                bool space = false;
                while ( fast != s.end() && *fast == ' ' ) {
                    ++fast;
                    space = true;
                }
                if ( space && fast != s.end() ) { // space between words not the trailing space
                    *slow = ' ';
                    ++slow;
                }
                while ( fast != s.end() && *fast != ' ') {
                    *slow = *fast;
                    ++slow;
                    ++fast;
                }

            }

        if ( slow != s.end() ) {
            *slow = '\0';
        }
        return string(s.c_str());
    }

    int wordsCount( string &s ) {
        int cnt = 0;
        for ( auto i = s.begin(); i != s.end(); ++i ) {
            if ( *i == ' ' ) {
                ++cnt;
            }
        }
        return cnt + 1;
    }

    void innerReverse(  string::iterator& left, string::iterator& right ) {
        while ( left < right ) {
            char tmp = *left;
            *left = *right;
            *right = tmp;
            ++left;
            --right;
        }
    }

public:
    void reverseWords(string &s) {

        if ( s.length() == 0 ) {
            return;
        }

        string pure = this->regularization(s);

        reverse(pure.begin() , pure.end());

        string::iterator edge = pure.begin();
        string::iterator left;

        while ( edge != pure.end() ) {
            left = edge;
            while ( edge != pure.end() && *edge != ' ' ) {
                ++edge;
            }
            auto right = edge - 1;
            this->innerReverse( left , right );
            if ( edge != pure.end() ) {
                ++edge;
            }
        }
        s = pure;

    }
};

// submit the codes above

int main() {
    string s = " ";
    Solution sl;
    sl.reverseWords(s);
    cout << s << endl;
    return 0;
}