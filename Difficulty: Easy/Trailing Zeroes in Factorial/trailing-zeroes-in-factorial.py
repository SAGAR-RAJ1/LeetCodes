class Solution:
    def trailingZeroes(self, n):
    	#code here 
    	ans=0
    	while n>=5:
    	    ans+=n//5
    	    n=n//5
    	return ans
    	