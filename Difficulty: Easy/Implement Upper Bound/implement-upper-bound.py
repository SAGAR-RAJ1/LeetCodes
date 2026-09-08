class Solution:
    def upperBound(self, arr, target):
        # code here
        
        n = len(arr);
        ans=n
        low = 0 
        high = n-1
        
        while low<=high:
            
            mid = low + (high -low)//2;
            
            if arr[mid]<=target :
                low = mid+1
            else :
                ans=min(ans,mid)
                high=mid-1
        
        
        return ans