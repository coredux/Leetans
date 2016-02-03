//
// Created by seanr on 2016/2/3.
//

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {

   while( head != NULL && head->val == val ) {
      struct ListNode* tmp = head;
      head = head->next;
      free( tmp );
   }

   struct ListNode* now = head;
   struct ListNode* pre = now;

   while( now != NULL ) {

      if( now->val == val ) { // remove

         pre->next = now->next;

         struct ListNode* tmp = now;
         now = now->next;
         free( tmp );

      } else {

         pre = now;
         now = now->next;

      }

   }

   return head;

}

int main() {
   removeElements( NULL , 0 );
   return 0;
}