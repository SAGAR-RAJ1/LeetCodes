class Solution:
    def longestUniqueSubstr(self, s):
        # code here
        ans=0
        left=0
        n=len(s)
        st=set()
        for right in range(0,n):
            if s[right] not in st:
                st.add(s[right])
            else:
                while left<=right and s[right] in st:
                    st.remove(s[left])
                    left+=1
                st.add(s[right])
            ans=max(ans,right-left+1)
        return ans
                
            
            