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
    ListNode* deleteMiddle(ListNode* head) {
      //here we will find middle node's previous node. so that deletion can happen.
      if(head->next==nullptr) return nullptr;
      ListNode *turtle = head, *rabbit = head , *prev = nullptr;
      while(rabbit!=nullptr && rabbit->next!=nullptr){
        prev=turtle;//storing in prev as it is going to change.
        turtle=turtle->next;
        rabbit=rabbit->next->next;
      }
      ListNode *temp = prev->next;
      prev->next=prev->next->next;
      delete temp;
      return head;
    }
};