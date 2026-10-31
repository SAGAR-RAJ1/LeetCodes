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
    int search(vector<int>&inorder,int target){
        int n = inorder.size();
        for(int i = 0 ; i<n;i++){
           if(inorder[i]==target)return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &preindex,int left , int right){
        if(left>right)return nullptr;

        TreeNode * temp = new TreeNode(preorder[preindex]);
        int index = search(inorder , preorder[preindex]);
        preindex++;

        temp->left=build(preorder,inorder,preindex,left,index-1);
        temp->right=build(preorder,inorder,preindex,index+1,right);

        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = 0;
        return build(preorder,inorder,m,0,n-1);
        
    }
};