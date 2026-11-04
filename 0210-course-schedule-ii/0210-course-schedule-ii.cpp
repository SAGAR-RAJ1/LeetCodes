class Solution {
public:
    stack<int>s;
    void dfs(int n, vector<vector<int>>& adj,vector<int>&visited,vector<int>&pathvisited){
        visited[n]=1;
        pathvisited[n]=1;

        for(auto &a:adj[n]){
            if(visited[a]==0){
                dfs(a,adj,visited,pathvisited);
            }else{
                if(pathvisited[a])return;
            }
        }

        pathvisited[n]=0;
        s.push(n);
        return;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>adj(n);
        if(n==1)return {0};
        for(auto &a:pre){
            adj[a[1]].push_back(a[0]);
        }
        
        vector<int>visited(n,0);
        vector<int>pathvisited(n,0);

        for(int i= 0 ;i<n;i++){
            if(visited[i]==0){
                dfs(i,adj,visited,pathvisited);
            }
        }

        vector<int>ans;
        if(s.size()!=n)return {};
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }


       return ans;


    }
};