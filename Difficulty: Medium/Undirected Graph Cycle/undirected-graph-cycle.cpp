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
		for (int j = 0 ; j<V; j++) {
			if(visited[j])continue;
			queue<pair<int, int>> q;
			q.push({j, -1});
			visited[j] = 1;
			while (!q.empty()) {
				
				auto a = q.front();
				q.pop();
				
				int node = a.first;
				int parent = a.second;
				
				for (auto & i : adj[node]) {
					if (visited[i] == 0) {
						visited[i] = 1;
						q.push({i, node});
					} else {
						if (i != parent)return true;
					}
				}
			}
		}
		return false;
	}
};
