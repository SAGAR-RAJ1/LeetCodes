class Solution {
	public:
	bool isBipartite(int V, vector<vector<int>> &edges) {
		// Code here
		vector<vector<int>> adj(V);
		
		for (auto &a:edges) {
			int u = a[0];
			int v = a[1];
			
			adj[u].push_back(v); adj[v].push_back(u);
		}
		
		queue<int>q;
		vector<int>visited(V, 0);
		vector<int>color(V, -1);
		for (int i = 0 ; i<V; i++) {
		    if (visited[i])[continue;
			q.push(i);
			visited[i] = 1;
			color[i] = 0;
			
			while (!q.empty()) {
				
				int node = q.front();
				q.pop();
				
				for (auto &a:adj[node]) {
					
					if (visited[a] == 0) {
						visited[a] = 1;
						color[a] = !color[node];
						q.push(a);
					} else {
						if (a != node && color[a] == color[node]) {
							return false;
						}
					}
				}
				
			}
		}
		return true;
		
	}
};
