class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
		for (auto &a:edges) {
			adj[a[0]].push_back({a[1],a[2]});
		
		}

		vector<int>dist(V, INT_MAX);
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
  
		q.push({0,0});
		dist[0] = 0;
		while (!q.empty()) {

			int node = q.top().second;
			int w = q.top().first;
			q.pop();
           
			for (auto &a:adj[node]) { 
                   int child = a.first;
                   int wt = a.second;
				if (dist[node] != INT_MAX && dist[node]+wt<dist[child]) {
					dist[child] = dist[node]+wt;
					q.push({dist[child],child});
				}
			}
		}
        
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }


		return dist;
    }
};
