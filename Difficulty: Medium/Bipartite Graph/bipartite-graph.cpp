class Solution {
  public:
    bool isBipartite(vector<vector<int>> &adj) {
        // Code here
        
        int n = adj.size();
        
        vector<int>color(n,-1);
        vector<int>visited(n,0);
        
        for(int i = 0 ;i<n;i++){
            
            if(visited[i]==0){
                queue<int>q;
                q.push(i);
                color[i]=1;
                visited[i]=1;
                
                while(!q.empty()){
                    
                    int node = q.front();
                    q.pop();
                    
                    for(auto &a:adj[node]){
                        if(visited[a]==0){
                            q.push(a);
                            color[a]=!color[node];
                            visited[a]=1;
                        }else{
                            if(color[a]==color[node])return false;
                        }
                    }
                    
                }
            }
        }
        return true;
    }
};