class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        for(int i = 0;i<m;i++){
            for(int j = 0 ; j<n ; j++){

                if(grid[i][j]=='1'){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]='2';
                    ans++;

                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for(int i = 0 ; i<4;i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];

                            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]=='1'){
                                grid[nr][nc]='2';
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }

        return ans;

    }
};