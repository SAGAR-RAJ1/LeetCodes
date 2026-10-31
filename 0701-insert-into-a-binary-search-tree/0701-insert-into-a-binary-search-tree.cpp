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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if(!root)return temp;
        TreeNode * ans = root;
        while(root){
            if(root->val>val){
                if(root->left==nullptr){
                    root->left=temp;
                    break;
                }else{
                    root=root->left;
                }
            }else{
               if(root->right==nullptr){
                    root->right=temp;
                    break;
                }else{
                    root=root->right;
                } 
            }
        }
        return ans;
    }
};