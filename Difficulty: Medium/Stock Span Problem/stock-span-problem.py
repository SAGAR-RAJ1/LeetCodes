from collections import deque
class Solution:
    def calculateSpan(self, arr):
        # code here
        
        st=deque()
        index=0
        ans=[]
        
        for a in arr:
            
            while st and st[-1][0]<=a:
                st.pop()
            
            if not st:
                ans.append(index+1)
            else:
                ans.append(index-st[-1][1])
            st.append((a,index))
            index+=1
            
        return ans
                
            
            