using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode {
    class AddDigits {

        public int doAddDigits( int num ) {

            while( num >= 10 ) {
                int ans = 0;
                while( num != 0  ) {
                    int tmp = num / 10;
                    int lastDigit = num - tmp * 10;
                    ans += lastDigit;
                    num = tmp;
                    
                }
                num = ans;
                ans = 0;
                
            }
            return num;
        }

    }
}