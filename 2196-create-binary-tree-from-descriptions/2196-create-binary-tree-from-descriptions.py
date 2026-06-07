
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:

        mp = {}
        childs = set()

        for parent, child, isLeft in descriptions:

            if parent not in mp:
                mp[parent] = TreeNode(parent)

            if child not in mp:
                mp[child] = TreeNode(child)

            if isLeft == 1:
                mp[parent].left = mp[child]
            else:
                mp[parent].right = mp[child]

            childs.add(child)

        for parent, child, isLeft in descriptions:
            if parent not in childs:
                return mp[parent]


# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna