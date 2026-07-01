/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = head->next;
        
        while(curr!=nullptr){
            curr->next=prev;
            prev=curr;
            curr=next;
          if(next)next=next->next;
        }
        
        return prev;
    }
};