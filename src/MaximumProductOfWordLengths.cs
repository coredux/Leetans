using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode {
    class MaximumProductOfWordLengths {
        public int MaxProduct(string[] words) {

            int maxProd = 0;

            for (int i = 0; i < words.Length; i++) {   
                string iWord = words[i];

                for (int j = 0; j < words.Length; j++) {
                    string jWord = words[j];
                    int tmpProd = iWord.Length * jWord.Length;
                    if (i != j && tmpProd > maxProd && !this.shareSameLetter( iWord , jWord ) ) {
                        maxProd = tmpProd;
                    }
                }
            }
            return maxProd;
        }

        private bool shareSameLetter( string a , string b ) {

            int[] alphaBet = new int[26];
            for( int i = 0; i < alphaBet.Length; i++ ) {
                alphaBet[i] = 0;
            }

            for( int i = 0; i < a.Length; i++ ) {
                char ch = a[i];
                alphaBet[ch - 'a'] += 1;
            } 

            for( int i = 0; i < b.Length; i++ ) {
                char ch = b[i];
                if( alphaBet[ ch - 'a'] > 0 ) {
                    return true;
                }
            }


            return false;
        }
    }
}
