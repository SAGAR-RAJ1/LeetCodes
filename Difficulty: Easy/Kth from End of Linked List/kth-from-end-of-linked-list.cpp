/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        vector<int>ans;
        while(head!=nullptr){
            ans.push_back(head->data);
            head=head->next;
        }
        
        int s = ans.size();
        if(s<k)return -1;
        
         return ans[s-k];
    }
};