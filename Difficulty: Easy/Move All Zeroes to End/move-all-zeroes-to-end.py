class Solution:
	def pushZerosToEnd(self, arr: list[int]) -> None:
    	# code here
    	start=-1
    	n = len(arr)
    	for i in range(0,n):
    	    if arr[i]==0:
    	        start=i
    	        break
    	if start==-1:
    	    return arr
    	
    	for i in range(start+1,n):
    	    if arr[i]!=0:
    	        arr[start],arr[i]=arr[i],arr[start]
    	        start+=1
    	return arr