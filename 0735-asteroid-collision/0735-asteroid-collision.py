class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        
        st=deque()

        for a in asteroids:
            if a>0:
                st.append(a)
            else:
                while st and st[-1]>0 and st[-1]<abs(a):
                    st.pop()
                if(st and st[-1]==abs(a)):
                    st.pop()
                elif not st or st[-1]<0:
                    st.append(a)
        return list(st)

                