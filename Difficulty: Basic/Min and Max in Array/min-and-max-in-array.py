class Solution:
    def getMinMax(self, arr):
        # code here
        
        mini=float('inf')
        maxi=float('-inf')
        
        for x in arr :
            if x<mini : mini=x
            if x>maxi : maxi=x
        
        return mini,maxi
            