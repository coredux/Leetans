#include <iostream>
#include <algorithm>

using namespace std;

// submit the codes below

class Solution {
private:

    string numTrim( string num ) {
        const char* p = num.c_str();
        while( *p != '\0' && *p == '0' ) {
            ++p;
        }
        if ( *p == '\0' ) {
            return string("0");
        } else {
            return string(p);
        }
    }

    string add ( string num1 , string num2 ) {
        const char * p1 = num1.c_str();
        const char * p2 = num2.c_str();
        string ret = "";
        int carry = 0;
        while( *p1 != '\0' || *p2 != '\0' ) {
            int n1 = ( *p1 == '\0' ? 0 : *p1 - '0');
            int n2 = ( *p2 == '\0' ? 0 : *p2 - '0');
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            int bit = tmp - carry * 10;
            ret += ( '0' + bit );
            if ( *p1 != '\0' ) {
                ++p1;
            }
            if ( *p2 != '\0' ) {
                ++p2;
            }
        }
        if ( carry > 0 ) {
            ret += ( '0' + carry );
        }
        return ret;
    }

    string multiplyPureNum( string num1 , string num2 ) {

        reverse( num1.begin() , num1.end() );
        reverse( num2.begin() , num2.end() );

        string ret = "";

        int offset = 0;
        for ( auto i = num1.begin(); i != num1.end() ; ++i ) {
            int n1 = *i - '0';
            string innerRet = "";
            int carry = 0;
            for ( auto j = num2.begin(); j != num2.end(); ++j ) {

                int n2 = *j - '0';

                int tmp = n1 * n2 + carry;
                carry = tmp / 10;
                int bit = tmp - carry * 10;

                innerRet += ( '0' + bit );
            }
            if ( carry > 0 ) {
                innerRet += ( '0' + carry );
            }

            string offsetedInnerRet = "";
            for ( int j = 0 ; j < offset ; ++j ) {
                offsetedInnerRet += '0';
            }
            offsetedInnerRet += innerRet;

            ret = this->add( ret , offsetedInnerRet );

            ++offset;
        }
        reverse( ret.begin() , ret.end() );
        return this->numTrim( ret );

    }

public:

    bool isPositive( string num ) {
        if ( num.c_str()[0] == '-' ) {
            return false;
        } else {
            return true;
        }
    }

    bool isLegal( string num ) {
        if ( num.length() == 0 ) {
            return false;
        }
        if ( num.c_str()[0] == '-' && num.length() == 1 ) {
            return false;
        }
        return true;
    }

    string getPureNum( string num ) {
        if ( this->isPositive(num)) {
            return num;
        } else {
            return string( &num.c_str()[1] );
        }
    }

    string multiply(string num1, string num2) {
        if ( !this->isLegal(num1) || !this->isLegal(num2) ) {
            return string("0");
        }
        bool flag1 = this->isPositive(num1);
        bool flag2 = this->isPositive(num2);
        string n1 = this->getPureNum(num1);
        string n2 = this->getPureNum(num2);
        if ( ( flag1 && flag2 ) || ( !flag1 && !flag2 ) ) {
            return this->multiplyPureNum( n1 , n2 );
        } else {
            return string("-").append( this->multiplyPureNum( n1 , n2 ));
        }
    }
};

// submit the codes above

int main() {
    Solution s;
    cout << s.multiply( "123" , "0" )<< endl;
    return 0;
}