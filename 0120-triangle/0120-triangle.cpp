class Solution {
public:
   vector<vector<int>>dp;
    int solve(vector<vector<int>>& triangle,int m , int n){
        int last =triangle.size();
        if(m==last-1)return triangle[m][n];
        if(dp[m][n]!=INT_MAX)return dp[m][n];

        int down = triangle[m][n] + solve(triangle,m+1,n);
        int dia = triangle[m][n] + solve(triangle,m+1,n+1);

        return dp[m][n]=min(dia,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        dp.assign(m,vector<int>(n,INT_MAX));
        return  solve(triangle,0,0);
    }
};
