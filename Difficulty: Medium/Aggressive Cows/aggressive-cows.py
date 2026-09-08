class Solution:
    def canput(self,arr,k,mid):
        
        count =1
        last = arr[0]
        
        for i in range(1,len(arr)):
            if arr[i]-last>=mid:
                count+=1
                last=arr[i]
        
        if count<k : return False
        return True
    def aggressiveCows(self, arr, k):
        # code here
        arr.sort()
        n=len(arr)
        low = 1
        high=arr[n-1]
        ans=float("-inf")
        
        
        while low<=high:
            
            mid = low + (high-low)//2
            if(self.canput(arr,k,mid)):
                ans=max(ans,mid)
                low=mid+1
            else:
                high=mid-1
        return ans
                
        
        