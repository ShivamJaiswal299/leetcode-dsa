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
    ListNode* oddEvenList(ListNode* head) {
      if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return head;//if there are 0 or 1 or 2 nodes.
      ListNode *odd = head, *even = head->next, *evenhead=head->next;
      while((even!=nullptr && odd!=nullptr) && (even->next!=nullptr && odd->next!=nullptr)){
        odd->next=odd->next->next;
        odd=odd->next;
        even->next=even->next->next;
        even=even->next;
      }
      odd->next=evenhead;
      return head;
    }
};