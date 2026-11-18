class Solution {
	public:
	int countDistinctIslands(vector<vector<char>> & grid) {
		// code here
		set<vector<pair<int, int>> >s;
		int n = grid.size();
		int m = grid[0].size();
		
		queue<pair<int, int>> q;
		vector<vector<int>> visited(n, vector<int>(m, 0));
		int dr[4] = {0, 0, 1, -1};
		int dc[4] = {1, -1, 0, 0};
		
		for (int i = 0 ; i<n; i++) {
			for (int j = 0 ; j<m; j++) {
				if (visited[i][j] == 0 && grid[i][j] == 'L') {
					q.push({i, j});
					visited[i][j] = 1;
					vector<pair<int, int>> temp;
					while (!q.empty()) {
						int r = q.front().first;
						int c = q.front().second;
						temp.push_back({r - i, c - j});
						q.pop();
						for (int i = 0; i<4; i++) {
							int nr = r + dr[i];
							int nc = c + dc[i];
							
							if (nr >= 0 && nc >= 0 && nr<n && nc<m && visited[nr][nc] == 0 && grid[nr][nc] == 'L') {
								q.push({nr,nc});
								visited[nr][nc]=1;
							}
						}
						
					}
					
					s.insert(temp);
					
				}
			}
		}
		
		return s.size();
	}
};
