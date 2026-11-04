class Solution {
public:

    vector<int> dijkstra(int src, int V,
                         vector<vector<pair<int,int>>>& adj) {

        vector<int> dist(V + 1, 1e9);

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &a : adj[node]) {

                int child = a.first;
                int wt = a.second;

                if(d + wt < dist[child]) {
                    dist[child] = d + wt;
                    pq.push({dist[child], child});
                }
            }
        }

        return dist;
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges,
                             int src, int dest) {

        vector<vector<pair<int,int>>> adj(V + 1);

        for(auto &a : edges) {
            int u = a[0];
            int v = a[1];
            int w = a[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Shortest distances from source
        vector<int> distSrc = dijkstra(src, V, adj);

        if(distSrc[dest] == 1e9)
            return {-1};

        // Shortest distances from destination
        vector<int> distDest = dijkstra(dest, V, adj);

        vector<int> ans;

        int node = src;
        ans.push_back(node);

        while(node != dest) {

            int next = -1;

            // Find smallest valid neighbour
            for(auto &a : adj[node]) {

                int child = a.first;
                int wt = a.second;

                if(distSrc[node] + wt + distDest[child] == distSrc[dest]) {

                    if(next == -1 || child < next)
                        next = child;
                }
            }

            if(next == -1)
                return {-1};

            node = next;
            ans.push_back(node);
        }

        return ans;
    }
};