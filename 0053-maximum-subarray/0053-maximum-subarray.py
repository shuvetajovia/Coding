class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_sum = nums[0]      # Global maximum
        current_sum = nums[0]  # Maximum sum ending at current index
        
        for i in range(1, len(nums)):
            # Decide whether to extend the subarray or start a new one
            current_sum = max(nums[i], current_sum + nums[i])
            
            # Update the global maximum
            max_sum = max(max_sum, current_sum)
        
        return max_sum