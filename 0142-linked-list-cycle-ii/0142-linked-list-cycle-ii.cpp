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
    ListNode *detectCycle(ListNode *head) {
        ListNode *turtle = head, *rabbit = head;
        int turtleDis=0;
        ListNode *meetingpnt=nullptr;
        while(rabbit!=nullptr && rabbit->next!=nullptr){
          rabbit=rabbit->next->next;
          turtle=turtle->next;
          turtleDis++;
          if(rabbit==turtle){
            meetingpnt = turtle;
            break;
          }
        }
        if(meetingpnt==nullptr) return meetingpnt;
        ListNode *temp = head;
        while(meetingpnt!=temp){
          meetingpnt=meetingpnt->next;
          temp=temp->next;
        }
        return meetingpnt;
    }
};