/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
/*  METHOD 1 - LESS SPACE EFFICIENT
    Node* copyRandomList(Node* head) {
      if(!head) return head; //as size can be zero
      Node *headsaver = head;
      Node dummy(0);
      Node* curr = &dummy;
      unordered_map <Node*,Node*> addofboth; //hashmap for storing addresses of nodes of both LL
      addofboth[nullptr]=nullptr; // a nullptr one is also requires as it is never added on its own.
      //traversing through the main LL while building the copy LL without random's connection, also updating the hash map.
      while(head!=nullptr){
          curr->next = new Node(0);
          curr=curr->next;
          curr->val=head->val;
          addofboth[head]=curr;
          head=head->next;
        }
      //reseting the heads' position
      head=headsaver;
      curr=dummy.next;
      //now linking the randoms'
      while(curr!=nullptr){
        curr->random=addofboth[head->random];
        curr=curr->next;
        head=head->next;
      }
      return dummy.next;
  // NOTE - THIS USES HASHMAP MAKING IT SPACE OF N , WE CAN DO IT WITHOUT HASHMAP MAKING IT CONSTANT SPACE.
    }
    */


  
  // METHOD 2 - SPACE IS CONSTANT
  Node* copyRandomList(Node* head) {
    if(!head) return head; //as size can be zero
    Node *headsaver = head;
    Node* temp=nullptr;
    //we will zip them in 1 LL (the original and the copy both)
    while(head!=nullptr){
      temp=new Node(0);
      temp->val=head->val;
      temp->next=head->next;
      head->next=temp;
      head=temp->next;
    }
    //now linking the random of the copy nodes with help of the original nodes
    head=headsaver;
    while(head!=nullptr){
      if(head->random != nullptr) head->next->random=head->random->next;
      head=head->next->next;
    }
    //now unzipping and breaking the link btw the original and copy.
    head = headsaver;
    Node* copyhead = head->next;
    Node* curr = copyhead;
    while(curr->next!=nullptr){
      temp = curr->next;
      curr->next=curr->next->next;
      head->next=temp;
      head=head->next;
      curr=curr->next;
    }
    head->next=nullptr;
    return copyhead;
  }
};