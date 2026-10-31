/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     bool ans = false;
     unordered_multiset<int>s;
     void inorder(TreeNode * root , int k){
        if(root==nullptr){
            return;
        }
        inorder(root->left,k);
       int rem = k-root->val;
         if(s.find(rem)!=s.end())ans=true;
       
        
        s.insert(root->val);
        inorder(root->right,k);
         

     }
    bool findTarget(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};