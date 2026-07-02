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
    int lengthOfLoop(Node *head) {
        // code here
        unordered_map<Node*,int>m;
        int timer = 1;
        while(head!=nullptr){
            
            if(m.find(head)!=m.end()){
                int value = m[head];
                return timer-value;
            }
            m[head]=timer;
            timer++;
            head=head->next;
        }
        
        return 0;
    }
};