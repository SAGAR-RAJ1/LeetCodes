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
        
        TreeNode * add = new TreeNode(val);
        TreeNode * ans = root;

        if(!root){
            return add;
        }

        while(root){

            int data = root->val;

            if(data<val){
                if(!root->right){root->right=add;break;}
                root=root->right;
            }else{
                if(!root->left){root->left=add;break;}
                root=root->left;
            }
        }

        return ans;
    }
};