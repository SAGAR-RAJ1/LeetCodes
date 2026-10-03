class Solution:
    # Function to find uncommon characters between two strings.
    def uncommonChars(self, s1, s2):
        #code here
        s=set()
        ans=""
        arr=[]
        for i in s1:
            s.add(i)
        for i in s2:
            if i not in s:
                arr.append(i)
                s.add(i)
        s.clear()
        for i in s2:
            s.add(i)
        for i in s1:
            if i not in s:
                arr.append(i)
                s.add(i)
        
        arr.sort()
        return "".join(arr)
            