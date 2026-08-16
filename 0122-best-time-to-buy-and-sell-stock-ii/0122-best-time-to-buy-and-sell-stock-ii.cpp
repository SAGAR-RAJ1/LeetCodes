class Solution {
public:
  vector<vector<int>>dp;
    int solve(vector<int>& prices,int i , int buy){
              int n = prices.size();
              if(i==n)return 0;
       
       if(dp[i][buy]!=-1)return dp[i][buy];

        if(buy){   // not buied        yes
        return dp[i][buy]=max(solve(prices,i+1,1),-prices[i]+solve(prices,i+1,0));
        }else{      // not sell           sell
         return dp[i][buy]=max(solve(prices,i+1,0),prices[i]+solve(prices,i+1,1));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.assign(n,vector<int>(2,-1));
        return solve(prices,0,1);
    }
};