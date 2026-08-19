class Solution {
  public:
    vector<int>visited;
    stack<int>s;
    
    void solve(int i, vector<vector<int>>& adj){
        
        visited[i]=1;
        
        for(auto &a:adj[i]){
            if(visited[a]==0){
                solve(a,adj);
            }
        }
        
        s.push(i);
        return;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>ans;
        vector<vector<int>>adj(V);
        
        for(auto &a:edges){
            adj[a[0]].push_back(a[1]);
        }
        visited.assign(V,0);
        
        for(int i = 0 ;i<V ; i++){
            if(visited[i]==1)continue;
            solve(i,adj);
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};