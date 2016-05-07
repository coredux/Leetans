#include <iostream>

using namespace std;

// submit the codes below

class Solution {
public:
    string reverseString(string s) {
        if ( s.length() < 1 )
        {
            return s;
        }
        string::iterator front = s.begin();
        string::iterator rear = s.end() - 1;
        while( front < rear )
        {
            char ch = *front;
            *front = *rear;
            *rear = ch;
            ++front;
            --rear;
        }
        return s;
    }
};

// submit the codes above

int main() {
    string s = "hello";
    Solution sol;
    cout << sol.reverseString(s) << endl;
    return 0;
}