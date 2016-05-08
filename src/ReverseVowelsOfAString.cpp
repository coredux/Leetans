#include <iostream>

using namespace std;

// submit the codes below

class Solution {
public:
    string reverseVowels(string s) {
        string::iterator front = s.begin();
        string::iterator rear = s.end() - 1;
        while( front < rear ) {
            while( front != s.end() && (!isVowel(*front)) ) {
                ++front;
            }
            while( rear > front && (!isVowel(*rear)) ) {
                --rear;
            }
            if ( front < rear ) {
                char tmp = *front;
                *front = *rear;
                *rear = tmp;
                ++front;
                --rear;
            }
        }
        return s;
    }

    bool isVowel( int ch ) {
        ch = tolower( ch );
        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) {
            return true;
        }
        return false;
    }
};

// submit the codes above

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}