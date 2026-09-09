class Solution:
    def reverseString(self, s: str) -> str:
        # code here
        ans=""
        for i in range(len(s)-1,-1,-1):
            ans+=s[i]
        return ans