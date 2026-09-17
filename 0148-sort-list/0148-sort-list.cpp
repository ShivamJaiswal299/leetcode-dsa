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
    ListNode* sortList(ListNode* head) {
      if(head==nullptr || head->next==nullptr) return head; //when node size is 0 or 1.
      ListNode *mid = midfinder(head);  //finding mid.
      ListNode *lefthead=head, *righthead=mid->next;
      mid->next=nullptr;  //breaking the list from mid.
      lefthead=sortList(lefthead);  //sort the left half.
      righthead=sortList(righthead);  //sort the right half.
      return merge2sortedLL(lefthead,righthead);  //merge the 2 sorted linked list and return them.
    }
private:
    ListNode* midfinder(ListNode *head){
      ListNode* turtle = head, *rabbit = head->next; //generally rabbit=head but here to find the correct mid we used head->next.
      while(rabbit!=nullptr && rabbit->next!=nullptr){
        turtle=turtle->next;
        rabbit=rabbit->next->next;
      }
      return turtle;
    }
    ListNode* merge2sortedLL(ListNode *i , ListNode *j){
      ListNode *k = new ListNode(-1); //k is initialize with a dummy node as we want to excess k->next so we have to do it.
      ListNode *khead=k;// we will delete the extra dummy node so we want this.
      while(i!=nullptr && j!=nullptr){
        if(i->val <= j->val){
          k->next = i;
          i=i->next;
        }else{
          k->next=j;
          j=j->next;
        }
          k=k->next;
      }
      while(i!=nullptr){
        k->next=i;
        i=i->next;
        k=k->next;
      }
      while(j!=nullptr){
        k->next=j;
        j=j->next;
        k=k->next;
      }
      ListNode *temp = khead;
      khead=khead->next;
      delete temp;
      return khead;
    }
};