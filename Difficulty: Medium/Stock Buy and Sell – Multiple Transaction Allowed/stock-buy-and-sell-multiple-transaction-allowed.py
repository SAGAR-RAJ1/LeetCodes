class Solution:
    def maxProfit(self, arr):
        # code here
        n=len(arr)
        dp=[[-1]*2 for i in range(n)]
        def solve(i,buy):
            if i==n:
                return 0
            if dp[i][buy]!=-1 :
                return dp[i][buy]
            if buy:
                dp[i][buy]=max(solve(i+1,1),-arr[i]+solve(i+1,0))
                return dp[i][buy]
            else:
                dp[i][buy]=max(solve(i+1,0),arr[i]+solve(i+1,1))
                return dp[i][buy]
        
        return solve(0,1)
