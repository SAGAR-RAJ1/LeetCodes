import bisect
class Solution:
    def rowWithMax1s(self, List: list[list[int]]) -> int:
        # code here
        ans=-1
        m=len(List)
        n=len(List[0])
        old=n
        for i in range(0,m):
            lb=bisect.bisect_left(List[i],1)
            if old>lb:
                ans=i
                old=lb
        return ans
        
            

        
        