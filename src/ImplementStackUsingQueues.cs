using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace LeetCode {
    public class Stack {

        private Queue<int> mainQue = new Queue<int>();
        private Queue<int> tmpQue = new Queue<int>();

        // Push element x onto stack.
        public void Push(int x) {
            mainQue.Enqueue(x);
        }

        // Removes the element on top of the stack.
        public void Pop() {
            while( mainQue.Count > 1 ) {
                tmpQue.Enqueue(mainQue.Dequeue());
            }
            mainQue.Dequeue();
            while( tmpQue.Count > 0 ) {
                mainQue.Enqueue(tmpQue.Dequeue());
            }
        }

        // Get the top element.
        public int Top() {
            while (mainQue.Count > 1) {
                tmpQue.Enqueue(mainQue.Dequeue());
            }
            int ret = mainQue.Peek();
            tmpQue.Enqueue(mainQue.Dequeue());
            while (tmpQue.Count > 0) {
                mainQue.Enqueue(tmpQue.Dequeue());
            }
            return ret;

        }

        // Return whether the stack is empty.
        public bool Empty() {
            return mainQue.Count == 0;
        }
    }
}
