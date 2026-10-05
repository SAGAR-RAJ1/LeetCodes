class Solution:
    def minWindow(self, s, p):
        # code here
        s1=len(s)
        s2=len(p)
        
        if s1<s2:
            return ""
        ans=""
        
        left=0
        need={}
        for i in p:
            need[i]=need.get(i,0)+1
        req=len(need)
        formed=0
        have={}
        for right in range(0,s1):
            ch=s[right]
            have[ch]=have.get(ch,0)+1
            
            if ch in need and have[ch]==need[ch]:
                formed+=1
            while formed==req:
                lch=s[left]
                
                if ans=="" or len(ans)>right-left+1:
                    ans=s[left:right+1]
                have[lch]-=1
                if lch in need and have[lch]<need[lch]:
                    formed-=1
                left+=1
        return ans
            