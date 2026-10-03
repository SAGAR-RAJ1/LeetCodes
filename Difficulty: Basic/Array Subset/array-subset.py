class Solution:
    def isSubset(self, a, b):
        # code here
        freq={}
        for i in a:
            freq[i]=freq.get(i,0)+1
        
        for i in b:
            
            if i not in freq:
                return False
            else:
                freq[i]-=1
                if freq[i]<0:
                    return False
        
        return True
            
    
    
    
    
