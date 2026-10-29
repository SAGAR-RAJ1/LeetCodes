/*
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
    Node * rev(Node*head){
        Node * curr=head;
        Node * prev = nullptr;
        
        while(curr){
            Node * next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        Node * h1 = rev(head1);
        Node * h2 = rev(head2);
        
        Node * ans = new Node(-1);
        Node * curr=ans;
        int carry = 0;
        while(h1 || h2){
             
             if(h1){
                 carry+=h1->data;
             }
             if(h2){
                 carry+=h2->data;
             }
             
             if(carry<10){
                 Node * temp = new Node(carry);
                 curr->next = temp;
                 curr=temp;
                 carry=0;
             }else{
                 Node * temp = new Node(carry%10);
                 curr->next = temp;
                 curr=temp;
                 carry=1;
             }
             
             if(h1)h1=h1->next;
             if(h2)h2=h2->next;
        }
        
        if(carry){
                 Node * temp = new Node(1);
                 curr->next = temp;
                 curr=temp;
        }
        
        Node * res = rev(ans->next);
        
        while(res->next && res->data==0)res=res->next;
        
        return res;
    }
};