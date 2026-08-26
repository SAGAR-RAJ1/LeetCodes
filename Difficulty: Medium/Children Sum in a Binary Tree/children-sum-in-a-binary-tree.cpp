/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  bool ans = true;
  
  void solve(Node * root){
      
      if(!root)return ;if(!root->left && !root->right)
                       return;
      int sum= 0 ;
      if(root->left)sum+=root->left->data;
      if(root->right)sum+=root->right->data;
      
      if(root->data!=sum)ans=false;
      
      solve(root->left);
      solve(root->right);
      
  }
    bool isSumProperty(Node *root) {
        // code here
        
        solve(root);
        return ans;
     
    }
};