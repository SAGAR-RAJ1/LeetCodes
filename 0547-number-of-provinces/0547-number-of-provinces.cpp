class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        vector<int> adj[m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;
        vector<int> visited(m, 0);
        for (int i = 0; i < m; i++) {

            if (visited[i] == 0) {
                ans++;
                queue<int> q;
                q.push(i);
                visited[i] = 0;

                while (!q.empty()) {

                    auto node = q.front();
                    q.pop();

                    for (auto& a : adj[node]) {
                        if (visited[a] == 0) {
                            q.push(a);
                            visited[a] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};