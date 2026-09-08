class Solution:
    def search(self, arr):
        n = len(arr)
        low = 0 
        high = n-1
        ans=float("inf")
        while low<=high:
            mid = low+ (high - low)//2
            #left  sorted
            if arr[mid]>=arr[low]:
                ans=min(ans,arr[low])
                low=mid+1
            else:
                ans=min(ans,arr[mid])
                high=mid-1
        
        return ans
    def findMin(self, nums: List[int]) -> int:
        return self.search(nums)
        