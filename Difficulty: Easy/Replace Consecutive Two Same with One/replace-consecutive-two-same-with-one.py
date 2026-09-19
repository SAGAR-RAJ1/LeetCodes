class Solution:
    def removeDuplicates(self, s):
        # code here
        st=[]
        
        for a in s:
            if not st or st[-1]!=a:
                st.append(a)
            else:
                while(st and st[-1]==a):
                    st.pop()
                st.append(a)
        
        return "".join(st)
        