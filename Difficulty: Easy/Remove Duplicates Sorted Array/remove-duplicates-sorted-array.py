class Solution:
    def removeDuplicates(self, arr):
        # code here 
        s=set()
        ans=[]
        for x in arr:
            if x not in s:
                ans.append(x)
                s.add(x)
        return ans
        
        
            