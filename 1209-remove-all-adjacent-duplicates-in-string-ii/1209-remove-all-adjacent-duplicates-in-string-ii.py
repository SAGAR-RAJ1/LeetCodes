class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        st=[]

        for a in s:
            if st and st[-1][0]==a:
                st[-1][1]+=1
                if st[-1][1]==k:
                    st.pop()
            else:
                st.append([a,1])
        ans=""
        for a in st:
            ans+=a[0]*a[1]
        return ans

