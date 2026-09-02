class Solution:
    def search(self, arr, x):
        # code here
        
        find = x
        length = len(arr)
        
        for i in range(length) :
            if arr[i]==find :
                return i
        return -1
    