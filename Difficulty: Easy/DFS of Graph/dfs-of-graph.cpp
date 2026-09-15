class Solution {
  public:
    vector<int>ans;
    void help(vector<vector<int>>& adj,int node,vector<int>&visited){
        visited[node]=1;
        ans.push_back(node);
        
        for(auto &a:adj[node]){
            if(visited[a]==0){
                visited[a]=1;
                help(adj,a,visited);
            }
        }
        
        return;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<int>visited(v,0);
        help(adj,0,visited);
        return ans;
        
    }
};