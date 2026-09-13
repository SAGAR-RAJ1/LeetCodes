# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        ans=[]

        reverse = False
        if(not root):return []
        q=deque()
        q.append(root)

        while q :
            temp=[]
            s=len(q)
            for i in range(0,s):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                temp.append(node.val)
            if(reverse):
                temp.reverse()
            ans.append(temp)
            reverse=not reverse
        return ans



        