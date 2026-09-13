/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*>m;

    void parent(TreeNode * root){

        if(!root)return ;
        if(root->left)m[root->left]=root;
        if(root->right)m[root->right]=root;
        parent(root->left);
        parent(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>ans;
        unordered_map<TreeNode*,int>visited;
        parent(root);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        visited[target]=1;
        while(!q.empty()){
            auto node = q.front().first;
            int dist=q.front().second;
            q.pop();
            
            if(dist==k)ans.push_back(node->val);
            if(dist>k)continue;

            if(node->left && visited[node->left]!=1){
                q.push({node->left,dist+1});
                visited[node->left]=1;
            }
            if(node->right && visited[node->right]!=1){
                q.push({node->right,dist+1});
                visited[node->right]=1;
            }
            if(m[node] && visited[m[node]]!=1){
                q.push({m[node],dist+1});
                visited[m[node]]=1;
            }
        }
        return ans;
    }
};