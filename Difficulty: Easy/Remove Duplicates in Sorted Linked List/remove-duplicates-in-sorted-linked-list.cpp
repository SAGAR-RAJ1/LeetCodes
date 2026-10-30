/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(!head->next)return head;
        
        Node * temp = head->next;
        Node * ref= head;
        
        while(temp){
            if(ref->data != temp->data){
                ref->next = temp;
                ref=ref->next;
            }
            temp=temp->next;
        }
        
        ref->next=nullptr;
        
        return head;
        
        
        
    }
};