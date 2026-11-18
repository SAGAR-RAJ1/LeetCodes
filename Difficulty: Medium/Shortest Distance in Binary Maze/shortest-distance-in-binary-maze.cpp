class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        
        int m = mat.size();
        int n = mat[0].size();
        
        
        if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0)return -1;
        if(src[0]==dest[0] && src[1]==dest[1])return 0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[src[0]][src[1]]=1;
        
        queue<pair<int,pair<int,int>>>q;
        
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        
        
        q.push({0,{src[0],src[1]}});
        
        
        while(!q.empty()){
            
            int steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            
            q.pop();
            
            for(int i = 0; i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 && mat[nr][nc]==1){
                    visited[nr][nc]=1;
                    if(nr==dest[0] && nc ==dest[1])return steps+1;
                    q.push({steps+1,{nr,nc}});
                }
            }
        }
        
        return -1;
    }
};
