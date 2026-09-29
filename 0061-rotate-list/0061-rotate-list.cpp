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
    ListNode* rotateRight(ListNode* head, int k) {
      //some special cases.
      if(head == nullptr || head->next == nullptr) return head;
      
      ListNode *newhead = head , *prev = head;
      //finding leangth.
      int length = 0;
      ListNode *curr= head;
      while(curr){
        length++;
        curr=curr->next;
      }
      k=k%length;
      if(k==0) return head;
      //we will place newhead at [length-k] as it is the correct head after rotation
      for(int i = 1;i<=length-k;i++){
        prev = newhead;
        newhead = newhead->next;
      }
      
      prev->next=nullptr;//breaking the link of previous node.
      //going at last and linking the last node with first.
      curr=newhead;
      while(curr){
        prev=curr;
        curr=curr->next;
      }
      prev->next = head;
      return newhead;
    }
};