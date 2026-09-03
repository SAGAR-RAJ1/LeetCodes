class Solution:
    def lowerBound(self, arr, target):
        # code here
        n=len(arr)
        ans=n
        
        
        for i,x in enumerate(arr):
            
            if(x>=target):
                ans=i
                break
        
        return ans
        
        