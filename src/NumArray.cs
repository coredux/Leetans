using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode {
    // leetcode303
    public class NumArray {

        private int[] numArr;
        private int[] numArrSum;

        public NumArray(int[] nums) {
            this.numArr = nums;
            this.numArrSum = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++) {

                if (i == 0) {
                    this.numArrSum[i] = nums[i];
                } else {
                    this.numArrSum[i] = nums[i] + this.numArrSum[i - 1];
                }

            }
        }

        public int SumRange(int i, int j) {

            if (i > 0) {
                return this.numArrSum[j] - this.numArrSum[i - 1];
            } else {
                return this.numArrSum[j];
            }

        }
    }
}
