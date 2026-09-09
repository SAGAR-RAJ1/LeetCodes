class Solution:
    def firstUniqChar(self, s: str) -> int:
        m={}
        for ch in s:
            m[ch]=m.get(ch,0)+1
        
        for i in range(0,len(s)):
            if(m.get(s[i])==1):
                return i
        return -1
        