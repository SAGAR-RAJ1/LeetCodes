class Solution:
    def removeDuplicates(self, s: str) -> str:
        ans=""
        st=deque()
        # st.append(s[0])
        n=len(s)

        for i in range(0,n):

            if len(st)==0 or st[-1]!=s[i]:
                st.append(s[i])
            else:
                    st.pop()
        
        return "".join(st)



            