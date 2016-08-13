#include <iostream>

using namespace std;

// submit the codes below

class Solution {
private:
    static const int MAX_TABLE_LEN = 30;
    int showTime[MAX_TABLE_LEN];

public:
    bool canConstruct(string ransomNote, string magazine) {
        this->init();
        for ( auto i = magazine.cbegin() ; i != magazine.cend() ; ++i ) {
            this->showTime[ *i - 'a' ] += 1;
        }
        for ( auto i = ransomNote.cbegin() ; i != ransomNote.cend(); ++i ) {
            if ( this->showTime[ *i - 'a'] <= 0 ) {
                return false;
            } else {
                this->showTime[ *i - 'a'] -= 1;
            }
        }
        return true;
    }

    void init() {
        for ( int i = 0 ; i < MAX_TABLE_LEN ; ++i ) {
            this->showTime[i] = 0;
        }
    }

};

// submit the codes above

int main() {
    Solution s;
    cout << s.canConstruct("aab" , "abcdea") << endl;
    return 0;
}