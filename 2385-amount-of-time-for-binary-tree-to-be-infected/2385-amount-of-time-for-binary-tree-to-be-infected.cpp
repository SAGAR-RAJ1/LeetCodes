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
    TreeNode* target = nullptr;
    unordered_map<TreeNode*,TreeNode*>parent;
    void findparent(TreeNode* root){

        if(root==nullptr)return;
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        findparent(root->left);
        findparent(root->right);
    }
    void find(TreeNode* root,int get){

        if(!root)return;
        if(root->val==get)target=root;
        find(root->left,get);
        find(root->right,get);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode * , bool>visited;
        int ans = 0 ;

        queue<TreeNode*>q;
        findparent(root);
        // auto target = find(start);
        find(root,start);
        q.push(target);
        visited[target]=true;

        while(!q.empty()){
            int s = q.size();
            for(int i = 0 ; i<s ;i++){
                auto node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
            ans++;
        }
        return ans-1;
    }
};