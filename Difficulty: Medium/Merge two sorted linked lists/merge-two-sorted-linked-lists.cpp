/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node * dummy = new Node (-1);
        Node * curr = dummy;
        
        while(head1!=nullptr && head2!=nullptr){
            
            if(head1->data<=head2->data){
                Node* temp = new Node(head1->data);
                curr->next=temp;
                curr=temp;
                head1=head1->next;
            }else{
                Node* temp = new Node(head2->data);
                curr->next=temp;
                curr=temp;
                head2=head2->next;
            }
        }
        
        while(head1!=nullptr){
                Node* temp = new Node(head1->data);
                curr->next=temp;
                curr=temp;
                head1=head1->next;
        }
        while(head2!=nullptr){
                Node* temp = new Node(head2->data);
                curr->next=temp;
                curr=temp;
                head2=head2->next;
        }
        curr->next=nullptr;
        return dummy->next;
    }
};