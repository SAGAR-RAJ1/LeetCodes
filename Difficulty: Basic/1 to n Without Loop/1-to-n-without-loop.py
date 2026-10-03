class Solution:
    def printTillN(self, n):
    	#code here 
    	def solve(i):
    	    if i<=0:
    	        return
    	    solve(i-1)
    	    print(i,end=" ")
    	solve(n)
    	    