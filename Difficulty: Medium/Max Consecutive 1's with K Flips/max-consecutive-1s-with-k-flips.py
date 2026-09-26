class Solution:
    def maxOnes(self, arr, k):
        # code here
        ans=0
        count=0
        n=len(arr)
        left=0
        
        for right in range(0,n):
            
            if arr[right]==0:
                count+=1
                if count>k:
                    while(count>k and left<=right):
                        if(arr[left]==0):
                            count-=1
                        left+=1
            
            ans=max(ans,right-left+1)
        
        return ans
                
            
        
            