class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int W, vector<int> &val, vector<int> &wt,int i){
        
        if(i<0)return 0;
        if(dp[i][W]!=-1)return dp[i][W];
        int notpick = 0 + solve(W,val,wt,i-1);
        int pick=INT_MIN;
        if(W>=wt[i])pick=val[i]+solve(W-wt[i],val,wt,i-1);
        
        return dp[i][W]=max(pick,notpick);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = val.size();
        dp.assign(n,vector<int>(W+1,-1));
        return solve(W,val,wt,n-1);
    }
};