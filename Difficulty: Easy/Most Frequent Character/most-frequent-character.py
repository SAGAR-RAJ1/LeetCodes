class Solution:
    def getMaxOccuringChar(self, s):
        # code here
        freq={}
        maxi=0
        for i in s:
            freq[i]=freq.get(i,0)+1
            maxi=max(maxi,freq[i])
            
        ans="z"
        for key,value in freq.items():
            if value==maxi and ord(ans)>ord(key):
                ans=key
        return ans
            
        
        