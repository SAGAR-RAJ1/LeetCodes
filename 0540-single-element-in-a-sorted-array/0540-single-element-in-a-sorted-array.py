class Solution:
    def singleNonDuplicate(self, arr: List[int]) -> int:

        n=len(arr)
        low = 1
        high = n-2

        if(n==1):return arr[0]

        if(arr[0]!=arr[1]):return arr[0]
        if(arr[n-1]!=arr[n-2]):return arr[n-1]

        while(low<=high):

            mid = low + (high-low)//2

            if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]):
                return arr[mid]
            
            if mid%2==0 :
                if arr[mid]==arr[mid+1]:
                    low=mid+1
                else:
                    high=mid-1
            elif mid%2!=0 :
                if arr[mid]==arr[mid+1]:
                    high=mid-1
                else:
                    low=mid+1
        return -1

