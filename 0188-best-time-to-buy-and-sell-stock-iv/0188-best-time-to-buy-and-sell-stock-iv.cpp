class Solution {
public:

 vector<vector<vector<int>>> dp;
int solve(vector<int>& prices,int i , int buy,int cap) {
       int n = prices.size();

       if(cap==-1)return 0;
       if(i==n)return 0;
       if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];

       if(buy){
        return dp[i][buy][cap]= max(solve(prices,i+1,1,cap),-prices[i]+solve(prices,i+1,0,cap));
       }else{
        return dp[i][buy][cap]=max(solve(prices,i+1,0,cap),prices[i]+solve(prices,i+1,1,cap-1));
       }
}

    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
            dp.assign(n, vector<vector<int>>(2, vector<int>(k, -1)));
          return solve(prices,0,1,k-1);
    }
};

