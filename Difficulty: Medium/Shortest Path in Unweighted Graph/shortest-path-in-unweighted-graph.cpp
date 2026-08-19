class Solution {
	public:
	int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
		// code here
		vector<vector<int>> adj(V);
		for (auto &a:edges) {
			adj[a[0]].push_back(a[1]);
			adj[a[1]].push_back(a[0]);
		}
		
		vector<int>dist(V, INT_MAX);
		
		queue<int>q;
		q.push(src);
		dist[src] = 0;
		
		while (!q.empty()) {
			
			int node = q.front();
			q.pop();
			
			for (auto &a:adj[node]) {
				
				if (dist[node] != INT_MAX && dist[node]+1<dist[a]) {
					dist[a] = dist[node]+1;
					q.push(a);
				}
			}
		}
		
		if (dist[dest] == INT_MAX)return - 1;
		
		return dist[dest];
		
	}
};
