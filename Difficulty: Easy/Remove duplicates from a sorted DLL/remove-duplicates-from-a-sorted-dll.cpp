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
     Node *  temp = head->next;
     Node * ref = head;
     
     while(temp != nullptr){
         
         while(temp != nullptr && temp->data == ref->data)temp=temp->next;
         
         if(temp==nullptr)break;
         
         ref->next=temp;
         temp->prev= ref;
         ref=temp;
     }
     
     ref->next=nullptr;
     
     return head;
    }
};