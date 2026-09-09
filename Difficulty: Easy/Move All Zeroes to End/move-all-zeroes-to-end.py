class Solution:
	def pushZerosToEnd(self, arr):
    	# code here
    	s = -1
    	n = len(arr)
    	for i in range(0, n):
    	    if arr[i] == 0:
    	        s = i
    	        break
    	if s==-1:return 
    	for i in range(s,n):
    	    if arr[i]!=0:
    	        arr[s],arr[i]=arr[i],arr[s]
    	        s+=1
    	        

