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
    bool solve(Node * root){
        if(!root)return true;
        if(!root->left && !root->right)return true;
        if(!solve(root->left) || !solve(root->right))return false;
        
        int l = 0,r=0;
        if(root->left)l=root->left->data;
         if(root->right)r=root->right->data;
         
         if(root->data != (l+r))return false;
         return true;
    }
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
        
    }
};