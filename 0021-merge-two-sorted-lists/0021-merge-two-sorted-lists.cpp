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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
      // very easy just like merge sort's merge function
      if(head1==nullptr) return head2;
      if(head2==nullptr) return head1;

      ListNode *curr=nullptr, *curr1=head1, *curr2=head2;
      ListNode *dummy = new ListNode();
      curr=dummy;
      while(curr1!=nullptr && curr2!=nullptr){
        if((curr1->val)<=(curr2->val)){
          curr->next=curr1;
          curr1=curr1->next;
        }
        else if((curr1->val)>(curr2->val)){
          curr->next=curr2;
          curr2=curr2->next;
        }
          curr=curr->next;
      }
      while(curr1!=nullptr){
        curr->next=curr1;
        curr1=curr1->next;
        curr=curr->next;
      }
      while(curr2!=nullptr){
        curr->next=curr2;
        curr2=curr2->next;
        curr=curr->next;
      }
      return ((head1->val) <= (head2->val)) ? head1 : head2;
    }
};