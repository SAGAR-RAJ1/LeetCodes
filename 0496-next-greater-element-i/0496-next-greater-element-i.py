class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans=[]
        st=deque()
        m={}

        for a in reversed(nums2):

            while st and a>=st[-1]:
                st.pop()
            if st:
                m[a]=st[-1]
            else:
                m[a]=-1
            st.append(a)

        for a in nums1:
            ans.append(m[a])
        return ans
