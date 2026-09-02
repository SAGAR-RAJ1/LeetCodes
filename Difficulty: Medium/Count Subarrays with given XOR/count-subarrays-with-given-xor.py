class Solution:
    def subarrayXor(self, arr, k):
        # code here
        
        m={}
        m[0]=1
        
        ans=0
        xor=0
        for x in arr:
            
            xor^=x
            find = k^xor
            
            if find in m :
                ans+=m[find]
            
            m[xor]=m.get(xor,0)+1
        
        
        return ans
            
            
            