class Solution:
    def firstUniqChar(self, s: str) -> int:

        arr=[0]*26

        for ch in s:
            arr[ord(ch)-ord('a')]+=1
        for i in range(0,len(s)):
            if arr[ord(s[i])-ord('a')]==1:
                return i
        return -1

        