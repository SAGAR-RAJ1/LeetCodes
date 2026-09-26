class Solution:
    def countSubarray(self, arr, k):
        # code here
        ans=0
        n=len(arr)
        curr=1
        left=0
        
        if k<=1:
            return 0
        for right in range(0,n):
            curr*=arr[right]
            
            while curr>=k:
                curr=curr//arr[left]
                left+=1
            ans+=(right-left+1)
        return ans
            
        