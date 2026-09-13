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
       //  verticle  node 
       map<int,int>m;
       queue<pair<int,Node*>>q;
       q.push({0,root});
       
       while(!q.empty()){
           int v = q.front().first;
           auto node = q.front().second;
           q.pop();
           
           if(m.find(v)==m.end()){
               m[v]=node->data;
           }
           
           if(node->left)q.push({v-1,node->left});
           if(node->right)q.push({v+1,node->right});
       }
       vector<int>ans;
       for( auto &a:m){
           ans.push_back(a.second);
       }
       return ans;
    }
};