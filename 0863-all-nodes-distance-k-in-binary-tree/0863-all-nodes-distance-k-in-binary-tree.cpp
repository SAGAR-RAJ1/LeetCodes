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
    unordered_map<TreeNode*,TreeNode*>m;
    void parent(TreeNode * root){
        
        if(root==nullptr)return;

        if(root->left){
            m[root->left]=root;
        }
        if(root->right){
            m[root->right]=root;
        }

        parent(root->left);
        parent(root->right);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        
        parent(root);
        queue<TreeNode *>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;

        while(!q.empty()){

            int s =q.size();
             
            for(int i = 0 ; i<s;i++){
                 
                 auto node = q.front();
                 q.pop();
                 if(k==0)ans.push_back(node->val);
                 if(node->left && !visited[node->left]){
                    q.push(node->left);visited[node->left]=true;
                    }
                 if(node->right && !visited[node->right]){
                    q.push(node->right);visited[node->right]=true;
                    }
                 if(m[node] &&  !visited[m[node]]){
                    q.push(m[node]);visited[m[node]]=true;
                 }

            }
            k--;

        }

        return ans;

    }
};