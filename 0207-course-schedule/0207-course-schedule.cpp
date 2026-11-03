class Solution {
public:
    bool dfs(int node , vector<vector<int>>&adj,vector<int>&visited,vector<int>&pathvisited){

        visited[node]=1;
        pathvisited[node]=1;

        for(auto&a:adj[node]){
            if(visited[a]==0){
                if(!dfs(a,adj,visited,pathvisited))return false;
            }else{
                if(pathvisited[a])return false;
            }
        }

         pathvisited[node]=0;
       
        return true;
    }
   
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);

        for(auto &a:prerequisites){
            adj[a[1]].push_back(a[0]);
        }
        
         vector<int>visited(n,0);
         vector<int>pathvisited(n,0);

         for(int i = 0 ; i<n ; i++){
            if(visited[i]==0){
                if(!dfs(i,adj,visited,pathvisited))return false;;
            }
         }
         
        
         return true;

    }
};