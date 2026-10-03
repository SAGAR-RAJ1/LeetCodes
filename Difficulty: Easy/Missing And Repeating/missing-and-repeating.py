class Solution:
    def findTwoElement(self, arr):
        # code here
        n=len(arr)
        freq={}
        for x in arr:
            freq[x]=freq.get(x,0)+1
        
        find=-1
        notfind=-1
        for i in range(1,n+1):
            if i in freq:
                if freq[i]==2:
                    find=i
            else:
                notfind=i
        
        return [find,notfind]
                
            

