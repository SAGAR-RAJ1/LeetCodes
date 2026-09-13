class Solution:
    dp=[]
    def solve(self,triangle,row,col):
        m=len(triangle)
        n=len(triangle[m-1])
        if(row==m-1):
            return triangle[row][col]
        if self.dp[row][col] != float("inf") :
            return self.dp[row][col]
        down=triangle[row][col]+self.solve(triangle,row+1,col)
        dia=triangle[row][col]+self.solve(triangle,row+1,col+1)

        self.dp[row][col]=min(down,dia)
        return self.dp[row][col]
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        m=len(triangle)
        n=len(triangle[m-1])
        self.dp=[[float("inf")]*n for i in range(0,m)]

        return self.solve(triangle,0,0)