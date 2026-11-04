class Solution {
	public:
	vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
		// Code here
		int n = adj.size();
		vector<int>dist(n, 1e9);
		
		priority_queue<pair<int, int>,
		
		vector<pair<int, int>>,
		
		greater<pair<int, int>> > q;
		dist[src] = 0;
		q.push({0, src});
		
		while (!q.empty()) {
			int d = q.top().first;
			int node = q.top().second;
			
			q.pop();
			if(d > dist[node]) continue;
			
			for (auto &a:adj[node]) {
				int adjnode = a[0];
				int wt = a[1];
				
				if ((d + wt)<dist[adjnode]) {
					dist[adjnode] = d + wt;
					q.push({dist[adjnode], adjnode});
				}
			}
		}
		
		return dist;
	}
};
