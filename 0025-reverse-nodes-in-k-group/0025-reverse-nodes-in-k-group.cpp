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
    ListNode* reverseLL(ListNode* head){
      if(head==nullptr) return nullptr;
      ListNode *curr = head, *prev=nullptr, *next = nullptr;
      while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *temp = head, *grphead=nullptr, *nexthead=nullptr,*prev=nullptr;
      bool flagforheadsaving=true;
      while(temp!=nullptr){ //temp will  become nullptr when perfect groups are formed.
        grphead=temp;
        for(int i=1;i<=k-1;i++){
          temp=temp->next;
          if(temp==nullptr) {
            prev->next = grphead;
            return head; //this block wont run if its a perfect grp.
          }
        }
        nexthead = temp->next;
        temp->next=nullptr;
        ListNode *reversekahead = reverseLL(grphead);
        // if(flagforheadsaving==true){
        //   head = reversekahead;
        //   flagforheadsaving=false;
        // }
        //alternate of the above comment out is the below if condition added.
        if(prev==nullptr) head = reversekahead;
        else if(prev!=nullptr) prev->next=reversekahead;
        prev=grphead;
        temp = nexthead;
      }
      return head;
    }
};