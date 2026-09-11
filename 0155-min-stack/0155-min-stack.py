from collections import deque

class MinStack:

    def __init__(self):
        self.dq = deque()
        self.mini = float("inf")

    def push(self, value: int) -> None:
        self.mini = min(value, self.mini)
        self.dq.append((value, self.mini))

    def pop(self) -> None:
        if not self.dq:
            return

        self.dq.pop()

        if not self.dq:
            self.mini = float("inf")
        else:
            self.mini = self.dq[-1][1]

    def top(self) -> int:
        if not self.dq:
            return -1

        return self.dq[-1][0]

    def getMin(self) -> int:
        if not self.dq:
            return -1

        return self.dq[-1][1]