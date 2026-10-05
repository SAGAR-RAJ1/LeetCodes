class Solution:
    def maximumPopulation(self, logs: list[list[int]]) -> int:
        ans=-1
        m={}
        for a,b in logs:
            m[a]=m.get(a,0)+1
            m[b]=m.get(b,0)-1
        curr=0
        maxsum=0
        for k,v in sorted(m.items()):
            curr+=v
            if curr>maxsum:
                maxsum=curr
                ans=k
        return ans
