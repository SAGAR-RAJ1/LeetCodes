/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        // code here
        vector<vector<int>>ans;
        Node * l = head;
        while(l->next){
            l=l->next;
        }
        Node * f = head;
        
        while(l->data>f->data){
            
            int sum =l->data+f->data;
            
            if(sum<target){
                f=f->next;
            }else if(sum>target){
                l=l->prev;
            }else{
                ans.push_back({f->data,l->data});
                  f=f->next;l=l->prev;
            }
        }
        
        return ans;
    }
};