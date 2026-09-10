class Solution:
    def solve(self,a,b):
        if b==0:
            return a
        return self.solve(b,a%b)
    def findGCD(self, nums: List[int]) -> int:
        a=min(nums)
        b=max(nums)
        return self.solve(b,a)
        