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

// NOTE - THIS PROBLEM HAS MULTIPLE ADVANCED SOLN WITH BETTER COMPLEXITY BUT CUZ OF KNOWLEDGE CONSTRAINTS, I DID THIS WITH - DIVIDE THE MULTIPLE LISTS INTO GROUPS OF 2 AND SORT THEM, AND APPLY THE SORT OF 2 LINKED LISTS RECURSIVELY WITH A NEW LL AND THE RESULT OF THE PREVIOUS LL. 

class Solution {
  
private: //----------------manually made functions.--------------------------
    ListNode *merge2Lists(ListNode* head1, ListNode* head2 ){//simple merge 2 LL function
      ListNode dummy;
      ListNode *curr = &dummy, *curr1 = head1, *curr2 = head2;
      while(curr1!=nullptr && curr2!=nullptr){
        if(curr1->val <= curr2->val){
          curr->next=curr1;
          curr1=curr1->next;
        }else{
          curr->next=curr2;
          curr2=curr2->next;
        }
        curr=curr->next;
      }
      curr->next=(curr1 != nullptr)? curr1: curr2;
      return dummy.next;

    }
    ListNode *mergeListsRecursively(vector<ListNode*>& lists, int curr ,int last){
      if(curr==last) return lists[last]; //reached the last node
      ListNode* lastLLmergedLL= mergeListsRecursively(lists,curr+1,last); //going further in the last
      return merge2Lists(lists[curr],lastLLmergedLL); //return the merged ll head
  }
public: //-------------------------the main function----------------------
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int size = lists.size();
      if(size==0) return nullptr; 
      return mergeListsRecursively(lists,0,size-1); //calling the recursive function
    }
};