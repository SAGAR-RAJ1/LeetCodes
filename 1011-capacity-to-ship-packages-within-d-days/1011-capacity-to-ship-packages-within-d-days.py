class Solution:
    def shipWithinDays(self, arr: List[int], days: int) -> int:
        
        n=len(arr)
        low = max(arr)
        high=0
        ans=float("inf")
        for a in arr: high+=a

        while low<=high:

            mid = low+(high-low)//2

            curr=0
            currdays=1
            for a in arr:

                if curr+a<=mid:
                    curr+=a
                else:
                    curr=a
                    currdays+=1
            
            if currdays<=days:
                ans=min(ans,mid)
                high=mid-1
            else:
                low=mid+1
        return ans