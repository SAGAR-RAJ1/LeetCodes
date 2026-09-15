class Solution {
	public:
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		vector<int>visited(V, 0);
		vector<vector<int>> adj(V);
		
		for (auto &a:edges) {
			int u = a[0];
			int v = a[1];
			
			adj[u].push_back(v); adj[v].push_back(u);
		}
		
		for (int i = 0 ; i<V; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				queue<pair<int, int>> q;
				q.push({i, -1});
				
				while (!q.empty()) {
					
					auto node = q.front().first; auto p = q.front().second;
					q.pop();
					
					for (auto&a:adj[node]) {
						
						if (visited[a] == 0) {
							q.push({a, node});
							visited[a] = 1;
						} else if (visited[a] == 1 && a != p) {
							return true;
						}
					}
				}
			}
		}
		
		return false;
	}
};
