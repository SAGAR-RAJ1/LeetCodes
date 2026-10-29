/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
   
    int cnt(Node *slow,Node * fast) {
        
        int count = 1;
        
        while(slow!=fast){
            fast=fast->next;
            count++;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        // code here
           Node * slow = head;
           Node * fast = head;
           if(!head || !head->next)return 0;
           while(fast && fast->next){

               slow=slow->next;
               fast=fast->next->next;

               if(slow==fast)return cnt(slow,fast->next);
           }
            return 0;
    }
};