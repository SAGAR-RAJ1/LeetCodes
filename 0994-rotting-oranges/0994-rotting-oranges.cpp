class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        int ans = -1;
        int fresh = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        while (!q.empty()) {

            int s = q.size();
            ans++;
            for (int i = 0; i < s; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < m && nc < n && nr >= 0 && nc >= 0 &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }
        }
        cout << fresh;
        if (fresh != 0)
            return -1;

        return ans;
    }
};