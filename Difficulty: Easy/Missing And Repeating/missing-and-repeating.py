class Solution:
    def findTwoElement(self, arr):
        # code here
        n=len(arr)
        freq={}
        for x in arr:
            freq[x]=freq.get(x,0)+1
        ans=[0,0]
        for i in range(1,n+1):
            
            if i not in freq:
                ans[1]=i
            else:
                if freq[i]>1:
                    ans[0]=i
        
        return ans
                
            

