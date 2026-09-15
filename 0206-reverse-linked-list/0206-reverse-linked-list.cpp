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
//iterative approach - curr will go on everynode (stops before last node ) , firstly we store curr->next so that its never lost  , then we can change curr->next to temp and temp always stores the previous node address that we previously visited. 
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr) return nullptr;
      ListNode *currnext = nullptr, *temp= nullptr,*curr = head;
      while(curr->next!=nullptr){
        currnext=curr->next;
        curr->next=temp;
        temp = curr;
        curr=currnext;
      }
      //here the last node isnt connected as we stoped the loop before , so doing it manually.
      curr->next= temp;
      head = curr;
      return head;
    }
};