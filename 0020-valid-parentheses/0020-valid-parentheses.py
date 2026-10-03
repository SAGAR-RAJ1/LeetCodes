class Solution:
    def isValid(self, s: str) -> bool:
        st=deque()
        for i in s:
            if i=='{' or i=='[' or i=='(':
                st.append(i)
            else:
                if len(st)==0:
                    return False
                if st[-1]=='{' and i=='}':
                    st.pop()
                elif st[-1]=='[' and i==']':
                    st.pop()
                elif st[-1]=='(' and i==')':
                    st.pop()
                else:
                    return False
        if len(st)!=0:
            return False
        return True
                
        