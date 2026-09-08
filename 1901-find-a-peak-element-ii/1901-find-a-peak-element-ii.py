class Solution:
    def find(self, mat: List[List[int]],col):
        m=len(mat)
        n=len(mat[0])

        maxi=-1
        row=-1

        for i in range(0,m):
            if(mat[i][col]>maxi):
                maxi=mat[i][col]
                row=i
        return row

    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m=len(mat)
        n=len(mat[0])

        start = 0
        end = n-1

        while start<=end:

            mid = start+(end-start)//2
            row = self.find(mat,mid)

            left:int
            right:int
            if mid-1>=0:
                left=mat[row][mid-1]
            else:
                left=-1
            if mid+1<n:
                right=mat[row][mid+1]
            else:
                right=-1
            if mat[row][mid]>left and mat[row][mid]>right:
                return [row,mid]
            elif mat[row][mid]<left:
                end=mid-1
            else:
                start=mid+1
        return -1

