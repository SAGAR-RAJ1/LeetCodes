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
}; */

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        //vertical  node
        map<int,int>m;
        vector<int>ans;
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int ver = q.front().second;
            auto node =q.front().first;
            q.pop();
            
            if(m.find(ver)==m.end()){
                m[ver]=node->data;
            }
            
            if(node->left)q.push({node->left,ver-1});
            if(node->right)q.push({node->right,ver+1});
        }
        
        for(auto &[u,v]:m){
            ans.push_back(v);
        }
        return ans;
    }
};