import sys
sys.setrecursionlimit(2000)

n = int(input())

def solve(i):
    if i == 0:
        return 0
    return solve(i - 1) + i

print(solve(n))