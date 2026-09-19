class Solution:
    def removePair(self, s):
        # code here
        st=[]
        
        for i in s:
            if not st or st[-1]!=i:
                st.append(i)
            else:
                st.pop()
        
        if not st :
            return "-1"
        
        return "".join(st)