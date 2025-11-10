class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        stack = []
        for x in nums:
            if x == 0:
                stack = []  # reset for Python 2 compatibility
                continue
            while stack and stack[-1] > x:
                stack.pop()
            if not stack or stack[-1] < x:
                stack.append(x)
                ans += 1
        return ans
