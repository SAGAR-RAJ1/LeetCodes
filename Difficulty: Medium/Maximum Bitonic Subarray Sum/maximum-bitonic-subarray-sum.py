class Solution:
    def maxBitonic(self, arr):
        n = len(arr)

        maxSum = arr[0]
        currentSum = arr[0]

        # 0 = starting
        # 1 = increasing
        # 2 = decreasing

        flag = 0

        for i in range(1, n):

            if arr[i] > arr[i - 1]:

                # If we were decreasing and now increase,
                # the old bitonic subarray is broken.
                if flag == 2:
                    currentSum = arr[i - 1] + arr[i]
                else:
                    currentSum += arr[i]

                flag = 1

            elif arr[i] < arr[i - 1]:

                # Enter/continue decreasing phase
                currentSum += arr[i]
                flag = 2

            else:
                # arr[i] == arr[i-1]

                if flag == 2:
                    # Equal after decreasing is NOT allowed
                    maxSum = max(maxSum, currentSum)
                    currentSum = arr[i]
                else:
                    # Equal while increasing/at peak is allowed
                    currentSum += arr[i]

            maxSum = max(maxSum, currentSum)

        return maxSum
