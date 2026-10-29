/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        
        if(!head->next)return head;
        
        Node * temp = head->next;
        Node * curr = head;
        while(temp){
            if(temp->data != curr->data){
                curr->next=temp;
                curr=temp;
            }
            temp=temp->next;
        }
        curr->next=nullptr;
        return head;
        
    }
};