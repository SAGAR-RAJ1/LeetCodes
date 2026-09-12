class StockSpanner:

    st=deque()
    index:int

    def __init__(self):
        self.st = deque()
        self.index = 0

    def next(self, price: int) -> int:
        if self.st:
            while( self.st and self.st[-1][0]<=price):
                self.st.pop()
            if self.st:
                ans= self.index-self.st[-1][1]
            else:
                ans= self.index+1
            self.st.append((price,self.index))
            self.index+=1
            return ans
        else:
            self.st.append((price,self.index))
            self.index+=1
            return 1

        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)