/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
    int length(Node * a, Node * b){
        int count = 1;
        
        while(a!=b){
            b=b->next;
            count++;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        // code here
        Node * slow = head;
        Node * fast = head;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                fast=fast->next;
                return length(slow,fast);
            }
        }
        return 0;
    }
};