class Solution {
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        set<vector<pair<int,int>>>s;
        
        vector<vector<int>>visited(m,vector<int>(n,0));
        
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        
        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j<n ; j++){
                
                if(visited[i][j]==1 || grid[i][j]=='W')continue;
                int sr = i;
                int sc = j;
                queue<pair<int,int>>q;
                q.push({sr,sc});
                visited[sr][sc]=1;
                vector<pair<int,int>>temp;
                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    temp.push_back({r-sr,c-sc});
                    for(int i = 0 ; i< 4 ; i++){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        
                        if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 && grid[nr][nc]=='L' ){
                            visited[nr][nc]=1;
                            q.push({nr,nc});
                        }
                    }
                   
                }
                
                 s.insert(temp);
                
            }
        }
        
        return s.size();
    }
};
