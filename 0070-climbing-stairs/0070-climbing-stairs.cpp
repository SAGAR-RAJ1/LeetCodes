class Solution {
public:
   vector<int>dp;
    int solve(int n){
        if(n==0)return 1;
        if(n==1)return 1;
         if(dp[n]!=-1)return dp[n];
        int l = solve(n-1);
        int r = solve(n-2);

        return dp[n]=l+r;

    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};