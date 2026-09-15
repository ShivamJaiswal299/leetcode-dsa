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
    ListNode* middleNode(ListNode* head) {
      //this can be done by linear traversal but we will use  TURTOISE HARE METHOD.
      //we will keep 2 pointers , turtle and hare, turtle moves 1 step at a time but hare moves 2. as soon as rabbit reaches end , the turtle will be at the middle of the race.
      ListNode* turtle = head, *rabbit = head;
      while(rabbit!=nullptr && rabbit->next!=nullptr){
        turtle=turtle->next;
        rabbit=rabbit->next->next;
      }
      return turtle;
    }
};