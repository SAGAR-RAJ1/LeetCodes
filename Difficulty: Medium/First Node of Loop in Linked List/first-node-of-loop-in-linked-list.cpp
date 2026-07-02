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
    int cycleStart(Node* head) {
        // code here
        unordered_set<Node*>m;
        
        Node* temp =head;
        while(temp!=nullptr){
            
            if(m.find(temp)!=m.end()){
                return temp->data;
            }
            m.insert(temp);
            temp=temp->next;
        }
        
        return -1;
    }
};