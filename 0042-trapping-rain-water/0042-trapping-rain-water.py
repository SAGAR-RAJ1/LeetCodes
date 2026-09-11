class Solution:
    def trap(self, height: List[int]) -> int:

        left=[]
        right=[]

        leftmax=float("-inf")
        for a in height:
            leftmax=max(leftmax,a)
            left.append(leftmax)
        rightmax=float("-inf")
        for a in reversed(height):
            rightmax=max(rightmax,a)
            right.append(rightmax)
        right=right[::-1]
        ans=0
        for i in range(0,len(height)):
            ans+=min(left[i],right[i])-height[i]
        return ans
        