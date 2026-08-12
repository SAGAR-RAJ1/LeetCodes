class Solution {
public:
     vector<vector<int>>dp;
    int solve(vector<vector<int>>& grid, int m ,int n){
        if(m==0 && n==0)return grid[m][n];
        if(m<0 || n<0)return 1e9;
         if(dp[m][n]!=-1)return dp[m][n];
        int up = grid[m][n]+solve(grid,m-1,n);
        int left = grid[m][n]+solve(grid,m,n-1);

        return dp[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1);
    }
};