class Solution:
    def fibonacciNumbers(self, n):
        ans = [0,1]
        mod=1e9+7
        if n==1:
            return ans
        
        for i in range(2,n+1):
            ans.append(int((ans[i-1]+ans[i-2])%mod))
        return ans
            