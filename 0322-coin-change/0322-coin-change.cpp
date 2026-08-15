class Solution {
public:
   vector<vector<int>>dp;
    int solve(vector<int>& coins, int amount,int i){
       
       if(i<0){
         if(amount==0)return 0;
         return 1e9;
       }
  if(dp[i][amount]!=-1)return dp[i][amount];
        int pick = 1e9;
        if(coins[i]<=amount)pick = 1+solve(coins,amount-coins[i],i);
        int notpick = solve(coins,amount,i-1);

        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,n-1);
        
        if(ans==1e9)return -1;
        return ans;
    }
};