/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        // code here
        unordered_set<Node * >s;
        while(head!=nullptr){
            if(s.find(head)!=s.end())return true;
            s.insert(head);
            head=head->next;
        }
        
        return false;
    }
};