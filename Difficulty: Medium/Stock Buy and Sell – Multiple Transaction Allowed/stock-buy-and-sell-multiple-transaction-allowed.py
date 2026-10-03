class Solution:
    def maxProfit(self, prices):
        # code here
        n=len(prices)
        dp=[[-1]*2 for i in range(n)]
        
        def solve(index,buy):
            if index>=n:
                return 0
            if dp[index][buy]!=-1 :
                return dp[index][buy]
            if buy:
                dp[index][buy]=max(solve(index+1,1),-prices[index]+solve(index+1,0))
            else:
                dp[index][buy]=max(solve(index+1,0),prices[index]+solve(index+1,1))
            return dp[index][buy]
        
        return solve(0,1)
                
                
