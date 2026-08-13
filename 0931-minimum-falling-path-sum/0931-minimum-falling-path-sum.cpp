class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>& matrix,int m , int n){
       int ml = matrix.size();
       int nl = matrix[0].size();

      if(n<0 || n>nl-1)return 1e9;
      if(m==ml-1)return matrix[m][n];
      if(dp[m][n]!=INT_MAX)return dp[m][n];

      int down = matrix[m][n]+solve(matrix,m+1,n);
      int dialeft = matrix[m][n]+solve(matrix,m+1,n-1);
      int diaright = matrix[m][n]+solve(matrix,m+1,n+1);

      return dp[m][n]=min({down,dialeft,diaright});

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int ml = matrix.size();
       int nl = matrix[0].size();

      
       int ans = INT_MAX;
       for(int i = 0 ; i< nl ; i++){
          dp.assign(ml,vector<int>(nl,INT_MAX));
          int temp = solve(matrix,0,i);
          ans=min(ans,temp);
       }

       return ans;
    }
};