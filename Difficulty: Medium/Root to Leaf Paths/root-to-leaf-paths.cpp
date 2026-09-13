/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
vector<vector<int>>ans;

    void p(Node* root,vector<int>temp) {
        // code here
        if(!root)return;
        if(!root->left && !root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(root->data);
        
        p(root->left,temp);
        p(root->right,temp);
        
    }
      vector<vector<int>> paths(Node* root) {
        // code here
        vector<int>temp;
        p(root,temp);
        return ans;
    }
};