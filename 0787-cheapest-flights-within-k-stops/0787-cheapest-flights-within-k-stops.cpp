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

        q.push({0,{src,0}});


        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int currdist = q.front().second.second;
            q.pop();

            if(stops>k)continue;

            for(auto &a:adj[node]){
                int child = a.first;
                int d = a.second;

                if(stops<=k && currdist+d<dist[child]){
                    dist[child]=currdist+d;
                    q.push({stops+1,{child,dist[child]}});
                }

                
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};