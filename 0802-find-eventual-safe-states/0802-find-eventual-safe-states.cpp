class Solution {
public:
    bool solve(int node,vector<vector<int>>& graph,vector<int>& visited,vector<int>& pathvisited,vector<int>& check){
         
         visited[node]=1;
         pathvisited[node]=1;

         for(auto &a:graph[node]){

            if(visited[a]==0){
                if(solve(a,graph,visited,pathvisited,check)){
                    return true;
                }
            }else if(pathvisited[a])return true;
         }

         pathvisited[node]=0;
         check[node]=1;

         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>pathvisited(n,0);
        vector<int>check(n,0);

        vector<int>ans;

        for(int i = 0 ;i<n;i++){
            if(visited[i]==0){
               solve(i,graph,visited,pathvisited,check);
            }
        }

        for(int i = 0 ;i<n;i++){
            if(check[i]==1){
             ans.push_back(i);
            }
        }

        return ans;
    }
};