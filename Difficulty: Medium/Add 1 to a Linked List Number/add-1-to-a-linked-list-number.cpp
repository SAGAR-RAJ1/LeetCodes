/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int help(Node * head){
        if(!head){
            return 1;
        }
        int carry = help(head->next);
        head->data+=carry;
        if(head->data<10)return 0;
        head->data=0;
        return 1;
    }
    Node* addOne(Node* head) {
        // code here
        int carry = help(head);
        
        if(carry){
            Node* temp = new Node(1);
            temp->next=head;
            head=temp;
            
        }
        return head;
        
    }
};