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
        Node * temp = new Node(-1);
        Node* ans = temp;
        while(head1 && head2){
            
            if(head1->data<=head2->data){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
                
            }else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
            
        }
        
        while(head1){
            temp->next=head1;
            temp=head1;
            head1=head1->next;
        }
        while(head2){
            temp->next=head2;
            temp=head2;
            head2=head2->next;
        }
        return ans->next;
    }
};