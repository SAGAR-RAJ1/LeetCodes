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
    Node* reverseList(Node* & head) {
        if(!head || !head->next)return head;

        Node * curr=head;
        Node * prev = nullptr;

        while(curr){
            Node * next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
    Node* addOne(Node* head) {
        // code here
        
       Node * h1 =  reverseList(head);
       Node * a = h1;
        
        int carry = 1;
        
        
        
        while(h1){
            int sum = carry+ h1->data;
            
            if(sum<10){
                h1->data=sum;
                carry=0;
                break;
            }else{
                h1->data = 0;
                carry =1;
            }
            h1=h1->next;
        }
        h1=reverseList(a);
        if(carry){
            Node * temp =new Node(1);
            temp->next = h1;
            h1=temp;
        }
        
        return h1;
        
    }
};