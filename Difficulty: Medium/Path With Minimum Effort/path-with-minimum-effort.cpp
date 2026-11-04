class Solution {
	public:
	int minCostPath(vector<vector<int>> & mat) {
		// code here
		int m = mat.size();
		int n = mat[0].size();
		
		vector<vector<int>> dist(m, vector<int>(n, 1e9));
		priority_queue<pair<int, pair<int, int>>
		, vector<pair<int, pair<int, int>>
		>, greater<pair<int, pair<int, int>>
		>> q;
		
		q.push({0,{0,0}});
		dist[0][0]=0;
		
		int dr[4]={1,-1,0,0};
		int dc[4]={0,0,1,-1};
		
		while(!q.empty()){
		    int d = q.top().first;
		    int r = q.top().second.first;
		    int c = q.top().second.second;
		    q.pop();
		    
		    for(int i = 0 ;i<4;i++){
		        int nr = r + dr[i];
		        int nc = c + dc[i];
		        
		        if(nr>=0 && nc>=0 && nr<m && nc<n ){
		            int effort = max(d,abs(mat[r][c]-mat[nr][nc]));
		            
		            if(effort<dist[nr][nc]){
		                q.push({effort,{nr,nc}});
		                dist[nr][nc]=effort;
		            }
		        }
		    }
		}
		
		return dist[m-1][n-1];
	}
};
