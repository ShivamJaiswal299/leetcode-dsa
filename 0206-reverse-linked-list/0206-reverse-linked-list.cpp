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
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr) return nullptr;
      ListNode *currnext = nullptr, *temp= nullptr,*curr = head;
      while(curr->next!=nullptr){
        currnext=curr->next;
        curr->next=temp;
        temp = curr;
        curr=currnext;
      }
      curr->next= temp;
      head = curr;
      return head;
    }
};