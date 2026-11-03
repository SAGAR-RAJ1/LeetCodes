class Solution {
  public:
    
    bool dfs(int node ,vector<vector<int>>& adj,vector<int>& visited,vector<int>& pathvisited){
        
        visited[node]=1;
        pathvisited[node]=1;
        
        for(auto &a:adj[node]){
            if(visited[a]==0){
            if(dfs(a,adj,visited,pathvisited))return true;
            }else{
                if(pathvisited[a]){
                    return true;
                }
            }
        }
        pathvisited[node]=0;
        return false;
    }
    bool isCyclic(vector<vector<int>>& adj){
        // code here
        int v = adj.size();

        vector<int>visited(v,0);
        vector<int>pathvisited(v,0);
        for(int i = 0 ; i<v ; i++){
            
            if(visited[i]==0){
             
                 if(dfs(i,adj,visited,pathvisited))return true;
            }
           
        }
        return false;
    }
};