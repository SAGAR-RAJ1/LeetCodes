/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_set<int>s;
        
        while(head2!=nullptr){
            s.insert(head2->data);
            head2=head2->next;
        }
        Node * dummy = new Node(-1);
        Node * curr = dummy;
        while(head1!=nullptr){
            
            if(s.find(head1->data)!=s.end()){
                 Node * temp = new Node(head1->data);
                 curr->next=temp;
                 curr=temp;
            }
            head1=head1->next;
        }
        curr->next=nullptr;
        return dummy->next;
    }
};