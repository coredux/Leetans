using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode {
    class Program {
        static void Main(string[] args) {
            MaximumProductOfWordLengths mp = new MaximumProductOfWordLengths();
            string[] x = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
            System.Console.WriteLine( mp.MaxProduct( x ) );
        }
    }
}
