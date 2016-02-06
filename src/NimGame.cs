using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode {
    // leetcode292
    // class Solution
    class NimGame {
        public bool CanWinNim(int n) {
            if( n % 4 != 0 ) {
                return true;
            }
            return false;
        }
    }
}
