from collections import deque;
class Solution:
    def bracketNumbers(self, s):
        ans = []
        count = 0
        st=deque()
        for i in s:
            if i=='(':
                count+=1
                ans.append(count)
                st.append(count)
            elif i==')':
                ans.append(st[-1])
                st.pop()
        return ans