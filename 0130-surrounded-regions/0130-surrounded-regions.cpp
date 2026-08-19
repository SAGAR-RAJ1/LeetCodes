class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O'){
                   q.push({i,j});
                   visited[i][j]=1;
                   board[i][j]='A';
                }
            }
        }

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ;i<4;i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc >=0 && nr<m && nc<n && board[nr][nc]=='O' && visited[nr][nc]==0){
                    board[nr][nc]='A'; visited[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j]=='O'){
                   board[i][j]='X';
                }
                if(board[i][j]=='A'){
                   board[i][j]='O';
                }

            }
        }

    }
};