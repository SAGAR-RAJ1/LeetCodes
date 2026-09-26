class Solution:
    def reverseWords(self, s):
        # code here
        words=s.split(".")
        temp=[]
        for i in words:
            if i!="":
                temp.append(i)
        temp.reverse()
        ans= ".".join(temp)
        return ans
        