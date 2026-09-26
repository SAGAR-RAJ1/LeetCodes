n = int(input())

# Increasing
for i in range(1, n + 1):
    print(" " * (n - i) + "* " * i)

# Decreasing
for i in range(n, 0, -1):
    print(" " * (n - i) + "* " * i)