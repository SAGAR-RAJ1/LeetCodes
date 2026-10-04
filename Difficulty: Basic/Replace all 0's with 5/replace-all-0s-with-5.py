class Solution:
    def convertFive(self, n):
        # code here
        num=str(n)
        ans=""
        for i in range(0,len(num)):
            if num[i]=='0':
                ans+='5'
            else:
                ans+=num[i]
        return int(ans)