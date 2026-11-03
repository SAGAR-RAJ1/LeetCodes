class Solution {
  public:
    bool dfs(int node,int parent,vector<int>&visited,vector<vector<int>>& adj){
        
        visited[node]=1;
        for(auto &a:adj[node]){
            if(visited[a]==0){
           if(dfs(a,node,visited,adj))return true;
            }else if(a!=parent){
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(vector<vector<int>>& adj){
        // Code here
        
        int m = adj.size();
        
        vector<int>visited(m,0);
        
        for(int i = 0 ; i<m;i++){
            if(visited[i]==0){
                if(dfs(i,-1,visited,adj))return true;
            }
        }
        return false;
    }
};