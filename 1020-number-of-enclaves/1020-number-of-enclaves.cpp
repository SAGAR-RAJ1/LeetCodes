class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1)&&grid[i][j]==1) {
                    q.push({i, j});
                    grid[i][j]=2;
                }
            }
        }
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 2;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]==1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};