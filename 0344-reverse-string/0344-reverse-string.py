class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n=len(s)
        s[0:n]=s[::-1]
            
        