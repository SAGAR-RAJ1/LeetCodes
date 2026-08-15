class Solution {
public:
   vector<vector<int>>dp;
    int solve(int amount, vector<int>& coins,int i ) {
        
        if(i<0){
             if(amount==0)return 1;
             return 0;
        }

        if(dp[i][amount]!=-1)return dp[i][amount];

        int pick =0;
        if(coins[i]<=amount)pick = solve(amount-coins[i],coins,i);

        int notpick = solve(amount,coins,i-1);

        return dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans = solve(amount,coins,n-1);
        return ans;
    }
};