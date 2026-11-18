class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i = 0 ; i<V-1;i++){
            for(auto &a:edges){
                int u = a[0];
                int v = a[1];
                int w = a[2];
                
                
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
         
            for(auto &a:edges){
                int u = a[0];
                int v = a[1];
                int w = a[2];
                
                
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                   return {-1};
                }
            }
        
        return dist;
    }
};
