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
    unordered_map<TreeNode*,TreeNode*>parent;
    void findp(TreeNode * root){
        if(root==nullptr)return;

        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        findp(root->left);
        findp(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        unordered_map<TreeNode*,bool>visited;
         
        queue<TreeNode*>q;
        int level = 0;
        findp(root);

        q.push(target);
        visited[target]=true;

        while(!q.empty()){
          int s = q.size();
          for(int i = 0 ; i<s;i++){
            auto node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);visited[node->right]=true;
            }
            if(parent[node] && !visited[parent[node]]){
                q.push(parent[node]);visited[parent[node]]=true;
            }
            if(level==k)ans.push_back(node->val);
          }
          level++;
          if(level>k)break;
        }

        return ans;

    }
};