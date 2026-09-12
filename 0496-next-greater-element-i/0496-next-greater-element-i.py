class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st=deque()
        m={}

        for a in reversed(nums2):

            while st and st[-1]<=a:
                st.pop()
            if st:
                m[a]=st[-1]
            else:
                m[a]=-1
            st.append(a)
        ans=[]
        for i in range(0,len(nums1)):
            ans.append(m[nums1[i]])
        return ans