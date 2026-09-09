class Solution:
    def countFreq(self, arr):
        #code here
        m={}
        for a in arr:
            m[a]=m.get(a,0)+1
        ans=[]
        for k,v in m.items():
            ans.append([k,v])
        return ans
            