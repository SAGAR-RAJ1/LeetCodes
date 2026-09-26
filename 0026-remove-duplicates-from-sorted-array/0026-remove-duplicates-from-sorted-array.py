class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n=len(nums)
        if n==1:
            return 1
        
        i=0
        for j in range(1,n):
            if nums[i]!=nums[j]:
                nums[i+1]=nums[j]
                i+=1
        
        return i+1

        