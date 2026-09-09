class Solution:
    def armstrongNumber (self, n):
        # code here 
        temp=n
        add=0
        while temp>0:
            last=temp%10
            add+=(last*last*last)
            temp//=10
        return add==n
            