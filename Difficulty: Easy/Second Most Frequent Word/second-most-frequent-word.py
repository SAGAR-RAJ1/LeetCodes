class Solution:
    def secFrequent(self, arr):
        # code here
        n=len(arr)
        if n==0:
            return -1
        maxi=0
        sec=-1
        freq={}
        for i in arr:
            freq[i]=freq.get(i,0)+1
            maxi=max(maxi,freq[i])
        
        for key,value in freq.items():
            if value!=maxi and value>sec:
                sec=value
        
        if sec==-1:
            return -1
        
        return sec
        
        