# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def solve(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root:
            return None
        if root==p or root==q:
            return root
        left=self.solve(root.left,p,q)
        right=self.solve(root.right,p,q)

        if left==None:
            return right
        elif right==None:
            return left
        else:
            return root
        
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        return self.solve(root,p,q)

        