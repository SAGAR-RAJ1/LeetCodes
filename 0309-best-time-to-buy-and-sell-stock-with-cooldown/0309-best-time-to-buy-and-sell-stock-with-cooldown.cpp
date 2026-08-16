class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& prices,int i , int buy,int cooldown){
        
        if(i==prices.size())return 0;
        if(dp[i][buy][cooldown]!=-1)return dp[i][buy][cooldown];
        if(buy){
            if(cooldown)return dp[i][buy][cooldown]=solve(prices,i+1,1,0);
            return dp[i][buy][cooldown]= max(solve(prices,i+1,1,0),-prices[i]+solve(prices,i+1,0,0));
        }else{
            return dp[i][buy][cooldown]=max(solve(prices,i+1,0,0),prices[i]+solve(prices,i+1,1,1));
        }


    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(2,-1)));

        return solve(prices,0,1,0);
    }
};