class Solution:
      
    def maxOnes(self, arr, k):
        # code here
        ans=0
        allowed=0
        left=0
        n=len(arr)
        for right in range(0,n):
            if arr[right]!=1 and allowed<=k:
                allowed+=1
            while left<=right and allowed>k:
                
                if arr[left]==0:
                    allowed-=1
                left+=1
            ans=max(ans,right-left+1)
        return ans
                
                
            
            