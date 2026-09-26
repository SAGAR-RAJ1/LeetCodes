class Solution:
    def maxSubarraySum(self, arr):
        # Code here
        ans=float("-inf")
        curr=0
        for x in arr:
            curr+=x
            ans=max(ans,curr)
            if curr<0:
                curr=0
        return ans
            