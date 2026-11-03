class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        queue<pair<int,int>>q;
        int m = image.size();
        int n = image[0].size();
        
        q.push({sr,sc});
        int prev=image[sr][sc];
        image[sr][sc]=color;
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};

        if(prev==color)return image;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i<4 ;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]==prev){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
           
        }
        return image;
    }
};