/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node * curr= head;
        Node * prev = nullptr;
        
        while(curr){
            Node * next = curr->next;
            
            curr->next=prev;
            curr->prev=next;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
};