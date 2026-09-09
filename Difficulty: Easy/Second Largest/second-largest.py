class Solution:
    def getSecondLargest(self, arr):
        # code here
        first = arr[0]
        second = -1
        for i in range(1, len(arr)):
            if arr[i]>first:
                second = first
                first = arr[i]
            elif arr[i]>second and arr[i] != first:
                second = arr[i]
        return second
