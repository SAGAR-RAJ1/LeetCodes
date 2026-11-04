class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {

        int m = mat.size();
        int n = mat[0].size();

        if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)
            return -1;

        queue<pair<int,pair<int,int>>> q;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        q.push({0,{src[0],src[1]}});
        dist[src[0]][src[1]] = 0;

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!q.empty()) {

            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            if(r == dest[0] && c == dest[1])
                return d;

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n &&
                   mat[nr][nc] == 1 && d + 1 < dist[nr][nc]) {

                    dist[nr][nc] = d + 1;
                    q.push({d+1,{nr,nc}});
                }
            }
        }

        return -1;
    }
};