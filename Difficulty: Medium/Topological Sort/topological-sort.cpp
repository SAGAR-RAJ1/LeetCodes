class Solution {
	public:
	void dfs(int node, vector<vector<int>> & adj, vector<int>&visited, stack<int>&s) {
		
		visited[node] = 1;
		
		for (auto &a:adj[node]) {
			if (visited[a] == 0) {
				dfs(a, adj, visited, s);
			}
		}
		
		s.push(node);
		return;
	}
	vector<int> topoSort(vector<vector<int>> & adj) {
		// code here
		
		int v = adj.size();
		
		vector<int>ans;
		stack<int>s;
		vector<int>visited(v, 0);
		
		for (int i = 0; i < v; i++) {
			
			if (visited[i] == 0) {
				
				dfs(i, adj, visited, s);
				
			}
			
		}
		while (!s.empty()) {
			ans.push_back(s.top()); s.pop();
		}
		
		return ans;
	}
};
