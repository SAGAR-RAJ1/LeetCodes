class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        q.push({sr,sc});
        int initial = image[sr][sc];
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        image[sr][sc]=color;
        visited[sr][sc]=1;
        while(!q.empty()){
           int r = q.front().first;
           int c = q.front().second;
           q.pop();

           for(int i = 0 ; i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]==initial && visited[nr][nc]==0){
                image[nr][nc]=color;
                visited[nr][nc]=1;
                q.push({nr,nc});
            }
           }
        }

        return image;
    }
};