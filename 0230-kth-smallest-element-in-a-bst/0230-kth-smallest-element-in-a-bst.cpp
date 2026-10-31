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
    int count = 1;
    int ans = -1;
    void travel(TreeNode * root , int k ){
        if(root==nullptr)return;
        travel(root->left,k);
        if(count==k)ans=root->val;
        count++;

        travel(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        travel(root,k);
        return ans;

    }
};