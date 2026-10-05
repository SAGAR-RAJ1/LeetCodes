class Solution:
    def minPlatform(self, arr: list[int], dep: list[int]) -> int:
        # code here
        events=[]
        for i in arr:
            events.append((i,1))
        for i in dep:
            events.append((i,-1))
        curr=0
        maxi=0
        for k,v in sorted(events,key=lambda x:(x[0],-x[1])):
            curr+=v
            if curr>maxi:
                maxi=curr
        return maxi
            