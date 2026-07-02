/* Node Structure
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* deleteMid(Node* head) {
        // code here
         if(head==nullptr || head->next==nullptr)return nullptr;
        Node * slow = head;
        Node * fast = head;

        fast=fast->next->next;

        while(fast!=nullptr && fast->next!=nullptr){
              fast=fast->next->next;
              slow=slow->next;
        }
       Node * dlt = slow->next;
       slow->next=dlt->next;
       delete(dlt);

       return head;
    }
};