class Solution {
	public:
	bool isBipartite(vector<vector<int>> &adj) {
		// Code here
		
		int m = adj.size();
		
		vector<int>color(m, -1);
		
		for (int i = 0 ; i<m; i++) {
			if (color[i] == -1) {
				color[i] = 1;
				queue<int>q;
				q.push(i);
				
				while (!q.empty()) {
					int node = q.front();
					q.pop();
					
					for (auto &a:adj[node]) {
						
						if (color[a] == -1) {
							color[a] = !color[node];
							q.push(a);
						} else {
							if (color[a] == color[node])return false;
						}
					}
				}
			}
		}
		return true;
	}
};
