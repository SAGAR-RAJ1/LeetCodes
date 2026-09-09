class Solution:
    def reverseArray(self, arr):
        # code here
        start = 0
		end = len(arr)-1
		while start<end:
		    arr[start],arr[end]=arr[end],arr[start]
		    start+=1
		    end-=1
        
        