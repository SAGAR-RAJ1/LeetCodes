class Solution:
    def intersect(self, a, b):
        # code here
        s=set()
        ans=[]
        for i in a:
            s.add(i)
        for i in b:
            if i in s:
                ans.append(i)
                s.discard(i)
        return ans
