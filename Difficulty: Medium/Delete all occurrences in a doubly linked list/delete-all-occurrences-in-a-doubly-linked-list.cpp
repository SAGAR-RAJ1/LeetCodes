/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {

        // code here
        Node * temp = head;
        
        while(temp!=nullptr){
            
            if(temp->data==x){
                
                if(temp==head){
                    head=head->next;
                }
                Node * nextnode = temp->next;
                Node * prevnode = temp->prev;
                
                if(nextnode)nextnode->prev=prevnode;
                if(prevnode)prevnode->next=nextnode;
                
                
            }
            temp=temp->next;
        }
        return head;
    }
};