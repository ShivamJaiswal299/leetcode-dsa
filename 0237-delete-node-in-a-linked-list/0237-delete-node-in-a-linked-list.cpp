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
    void deleteNode(ListNode* node) {
        //we will copy the data of node->next in node the delete the node->next and connect node with node->next->next.
        node->val=node->next->val;
        node->next=node->next->next;
    }
};