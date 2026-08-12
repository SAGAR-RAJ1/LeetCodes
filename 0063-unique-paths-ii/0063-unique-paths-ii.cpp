class Solution {
public:
     vector<vector<int>>dp;
     int solve(vector<vector<int>>& grid,int m , int n ){
       
        if(m<0 || n<0)return 0;
        if(grid[m][n] == 1)return 0;
         if(m==0 && n==0)return 1;
        if(dp[m][n]!=-1)return dp[m][n];

        int left = solve(grid,m,n-1);
        int up = solve(grid,m-1,n);

        return dp[m][n]=left + up;
     }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        // if(m==1 && n==1){
        //     if(g[])
        // }
        dp.assign(m,vector<int>(n,-1));
        return solve(g,m-1,n-1);
    }
};