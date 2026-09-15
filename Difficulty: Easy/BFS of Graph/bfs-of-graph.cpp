class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		// code here
		vector<int>ans;
		int v = adj.size();
		vector<int>visited(v, 0);
		
		queue<int>q;
		q.push(0);
		visited[0] = 1;
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			ans.push_back(node);
			for (auto &a:adj[node]) {
				if (visited[a] == 0) {
					q.push(a);
					visited[a] = 1;
				}
			}
			
		}
		return ans;
	}
};
