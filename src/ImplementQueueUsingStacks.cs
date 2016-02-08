using System.Collections;

namespace LeetCode {
    public class Queue {

        private Stack<int> mainStk = new Stack<int>();
        private Stack<int> tmpStk = new Stack<int>();

        // Push element x to the back of queue.
        public void Push(int x) {
            mainStk.Push(x);
        }

        // Removes the element from front of queue.
        public void Pop() {
            while( mainStk.Count > 0 ) {
                tmpStk.Push( mainStk.Pop() );
            }
            tmpStk.Pop();
            while( tmpStk.Count > 0 ) {
                mainStk.Push(tmpStk.Pop());
            }
        }

        // Get the front element.
        public int Peek() {
            while (mainStk.Count > 0) {
                tmpStk.Push(mainStk.Pop());
            }
            int dest = tmpStk.Peek();
            while (tmpStk.Count > 0) {
                mainStk.Push(tmpStk.Pop());
            }
            return dest;
        }

        // Return whether the queue is empty.
        public bool Empty() {
            if( mainStk.Count == 0 ) {
                return true;
            }
            return false;
        }
    }
}