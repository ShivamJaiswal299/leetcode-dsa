/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      //as all the last nodes are common , so trick is that find the length of both lists and then move ahead the longer list node so that both are at same distance from the end.then traverse them together and check at every step.
      int lenA = 0,lenB = 0;
      ListNode *curr = headA;
      //now checking for list A.
      while(curr!=nullptr){
        lenA++;
        curr=curr->next;
      }
      //now checking for list b.
      curr = headB;
      while(curr!=nullptr){
        lenB++;
        curr=curr->next;
      }
      
      if(lenA>lenB) for(int i=1;i<=lenA-lenB;i++) headA=headA->next;
      else if (lenA<lenB) for(int i=1;i<=lenB-lenA;i++) headB=headB->next;
      while(headA!=nullptr){
        if(headA==headB) return headA;
        headA = headA->next;
        headB = headB->next;
      }
      return nullptr;
    }
};