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

    int widthOfBinaryTree(TreeNode* root) {
       
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
long long ans = 0;
        while(!q.empty()){
            int s = q.size();
            long long start=0;
            long long end = 0;
            long long starting = q.front().second;
            for(int i = 0 ; i<s;i++){
            auto node = q.front().first;
            auto curr = q.front().second-starting;
            q.pop();
            
            if(node->left)q.push({node->left,2*curr+1});
            if(node->right)q.push({node->right,2*curr+2});

            if(i==0)start=curr;
            if(i==s-1)end=curr;
            }
            ans=max(ans,end-start+1);       
        }
return ans;
    }
};