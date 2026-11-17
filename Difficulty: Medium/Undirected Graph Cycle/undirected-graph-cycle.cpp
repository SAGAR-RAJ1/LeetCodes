class Solution {
  public:
    bool dfs(vector<int>& visited,vector<vector<int>>& adj , int node , int parent){
        
        visited[node]=1;
        
        for(auto &a:adj[node]){
            if(visited[a]==0){
                if(dfs(visited,adj,a,node))return true;
            }else{
                if(a!=parent)return true;
            }
        }
        
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj){
        // Code here
        int v = adj.size();
        vector<int>visited(v,0);
        
        for(int i = 0 ; i<v;i++){
            if(visited[i]==0){
                if(dfs(visited,adj,i,-1))return true;
            }
        }
        
        return false;
    }
};