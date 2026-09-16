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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //LOGIC -  take 2 pointers 'behind' , 'ahead' ; move "ahead" n steps ahead , now when 'ahead' reaches end , 'behind' will be at the req position.
    if(head->next==nullptr) return nullptr;
    ListNode *behind =head, *ahead = head , *temp = nullptr;
    //moving ahead n steps ahead.
    for(int i = 1;i<=n;i++) ahead=ahead->next;
    if(ahead==nullptr){
      temp = head;
      head=head->next;
      delete temp;
      return head;
      }
    while(ahead->next!=nullptr){
      ahead=ahead->next;
      behind=behind->next;
    }
    temp = behind->next;
    behind->next=behind->next->next;
    delete temp;
    return head; 
    }
};