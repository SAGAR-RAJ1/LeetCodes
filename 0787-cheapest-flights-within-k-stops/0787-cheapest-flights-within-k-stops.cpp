class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto &a:flights){
          int u = a[0];
          int v = a[1];
          int w = a[2];
          adj[u].push_back({v,w});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
           
           int steps = q.front().first;
           int node = q.front().second.first;
           int d = q.front().second.second;
 
           q.pop();
           if(steps>k)continue;

           for(auto &a:adj[node]){
            int adjnode = a.first;
            int wt = a.second;
            if(wt+d<dist[adjnode] && steps<=k){
                q.push({steps+1,{adjnode,wt+d}});
                dist[adjnode]=wt+d;
            }
           }
        }

        if(dist[dst]==1e9)return -1;
        return dist[dst]
;    }
};