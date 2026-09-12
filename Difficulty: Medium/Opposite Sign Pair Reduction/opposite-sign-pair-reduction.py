from collections import deque
from typing import List
class Solution:
    
    def reducePairs(self, arr):
        # code here
        st=deque()
        
        for a in arr:
            if not st or (st[-1]<0 and a<0) or (st[-1]>0 and a>0):
                st.append(a)
            else:
                while(st and abs(st[-1])<abs(a)):
                    st.pop()
                
                if(st and abs(st[-1])==abs(a)):
                    st.pop()
                    continue
                if not st:
                    st.append(a)
        
        return list(st)
                    