class Solution {
public:
    vector<vector<int>>dp;
    int solve(int e , int f){
      
      if(e==1)return f;

      if(f==0 || f==1)return f;
      if(dp[e][f]!=-1)return dp[e][f];
       
       int ans = INT_MAX;
      for(int i = 1 ; i<=f ; i++){
        int temp = 1 + max(solve(e-1,i-1),solve(e,f-i));
        ans=min(temp,ans);
      }

      return dp[e][f]=ans;
    }
    int twoEggDrop(int n) {
        dp.assign(3,vector<int>(n+1,-1));
        return solve(2,n);
    }
};