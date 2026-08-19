class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
         int n = mat[0].size();

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i = 0 ; i< m ; i++){
           for(int j = 0 ; j < n ; j++){
             if(mat[i][j]==0){
                q.push({0,{i,j}});
                visited[i][j]=1;
             }
           } 
        }

        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int r = t.second.first;
            int c = t.second.second;
            int dist = t.first;
            
            for(int i = 0 ; i<4;i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && mat[nr][nc]==1 && visited[nr][nc]==0){
                    mat[nr][nc]=dist+1;
                    visited[nr][nc]=1;
                    q.push({dist+1,{nr,nc}});
                }
            }


        }

        return mat;
    }
};