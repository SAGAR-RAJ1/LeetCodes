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
        
        if(!head->next)return nullptr;
        Node * slow=head;
        Node * fast = head->next->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next=slow->next->next;
        
        return head;
    }
};