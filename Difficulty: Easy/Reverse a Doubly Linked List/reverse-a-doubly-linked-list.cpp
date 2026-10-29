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
        Node * curr = head;
        Node * prev = nullptr;
        
        if(!head->next)return head;
        
        while(curr!=nullptr){
            curr->prev = curr->next;
            curr->next = prev;
            prev=curr;
            curr=curr->prev;
            
    
        }
        
        
        return prev;
        
        
    }
};