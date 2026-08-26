/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_multiset<int>s;
    bool solve(Node *root, int target){
        if(root==nullptr)return false;
        
        int find = target-root->data;
        
        if(s.find(find)!=s.end())return true;
          s.insert(root->data);
        if(solve(root->left,target))return true;
      
        if(solve(root->right,target))return true;
        
        return false;
    }
    bool findTarget(Node *root, int target) {
        // code here.
        
        return solve(root,target);
        
        
    }
    
};