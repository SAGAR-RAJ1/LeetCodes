/* Node Structure
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
    
     
     bool isleaf(Node * root){
         if(!root)return false;
         if(!root->left && !root->right)return true;
         return false;
     }
     
     void left(Node *root, vector<int>&ans){
         if(root==nullptr)return;
         if(!isleaf(root))ans.push_back(root->data);
         if(root->left)left(root->left,ans);
         else left(root->right,ans);
     }
       void right(Node *root,stack<int> &s){
         if(root==nullptr)return;
         if(!isleaf(root))s.push(root->data);
         if(root->right)right(root->right,s);
         else right(root->left,s);
     }
     void leaf(Node *root, vector<int>&ans){
         
         if(root==nullptr)return;
         
         leaf(root->left,ans);
         if(isleaf(root))ans.push_back(root->data);
         leaf(root->right,ans);
     }
    vector<int> boundaryTraversal(Node *root) {
        // code here
         vector<int>ans;
         stack<int>s;
         if(isleaf(root))
         return {root->data};
         
         ans.push_back(root->data);
         left(root->left,ans);
         
         leaf(root,ans);
         
         
         right(root->right,s);
         
         while(!s.empty()){
             ans.push_back(s.top());
             s.pop();
         }
        
         
         return ans;
         
       
    }
};