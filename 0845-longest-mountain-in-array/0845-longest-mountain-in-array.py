class Solution:
    def longestMountain(self, arr):
        n = len(arr)

        if n < 3:
            return 0

        left = [1] * n
        right = [1] * n

        # Increasing length ending at i
        for i in range(1, n):
            if arr[i] > arr[i - 1]:
                left[i] = left[i - 1] + 1

        # Decreasing length starting at i
        for i in range(n - 2, -1, -1):
            if arr[i] > arr[i + 1]:
                right[i] = right[i + 1] + 1

        ans = 0

        # Find peaks
        for i in range(1, n - 1):

            if arr[i] > arr[i - 1] and arr[i] > arr[i + 1]:

                length = left[i] + right[i] - 1

                ans = max(ans, length)

        return ans