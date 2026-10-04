n = int(input())

# code here
for i in range(n,0,-1):
    stars=2*i-1
    space=n-i
    print(" "*space + "*"*stars)