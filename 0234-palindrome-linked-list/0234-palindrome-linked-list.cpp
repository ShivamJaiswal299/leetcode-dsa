/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      //firstly we will find the middle node
      ListNode *rabbit = head, *turtle =head;
      bool ans = true;
      while(rabbit!=nullptr &&  rabbit->next!=nullptr && rabbit->next->next!=nullptr){
        rabbit=rabbit->next->next;
        turtle=turtle->next;
      }
      //now reversing the next half of the linked list.
      ListNode *headprev = turtle;
      turtle=turtle->next;
      ListNode *curr=turtle , *prev=nullptr , *next=nullptr;
      while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      headprev->next=prev;
      ListNode *firsthalf = head, *secondhalf = headprev->next;
      //now checking both the halves.
      while(secondhalf!=nullptr){
        if(firsthalf->val != secondhalf->val){
          ans=false;
          break;
        }
        firsthalf=firsthalf->next;
        secondhalf=secondhalf->next;
      }
      //now as we changed the linked list lets undo it.
      curr=headprev->next,prev=nullptr,next=nullptr;
      while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      headprev->next=prev;

      return ans;
    }
};