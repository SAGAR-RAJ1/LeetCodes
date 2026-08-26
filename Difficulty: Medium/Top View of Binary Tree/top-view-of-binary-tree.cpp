/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>m;
        
        queue<pair<Node *,int>>q;
        q.push({root,0});
        while(!q.empty()){
            
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            
            if(m.find(level)==m.end()){
                m[level]=node->data;
            }
            
            if(node->left)q.push({node->left,level-1});
            if(node->right)q.push({node->right,level+1});

            
        }
        
        for(auto &a:m){
            ans.push_back(a.second);
        }
        
        return ans;
    }
};