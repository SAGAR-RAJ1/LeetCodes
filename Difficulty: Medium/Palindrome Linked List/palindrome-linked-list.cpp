/*
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
    bool isPalindrome(Node *head) {
        //  code here
        stack<int>s;
        Node* temp = head;
        while(temp!=nullptr){
            s.push(temp->data);
            temp = temp -> next;
            
        }
        while(head!=nullptr){
           if(s.top()!=head->data)return false; 
           head=head->next;
           s.pop();
        }
        
        return true;
    }
};