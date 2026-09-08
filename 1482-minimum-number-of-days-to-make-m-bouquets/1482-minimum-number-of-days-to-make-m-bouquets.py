class Solution:
    def minDays(self, arr: List[int], m: int, k: int) -> int:
        n=len(arr)

        if(m>n/k):return -1

        start=min(arr)
        end=max(arr)
        ans=float("inf")

        while start<=end:
            mid = start+(end-start)//2
            canmake=0
            curr=0
            for i in arr:
                if i<=mid:
                    curr+=1
                    if curr==k:
                        canmake+=1
                        curr=0
                else:
                    curr=0
            
            if canmake>=m:
                ans=min(ans,mid)
                end=mid-1
            else:
                start=mid+1
        if ans== float("inf") : return -1
        return ans
