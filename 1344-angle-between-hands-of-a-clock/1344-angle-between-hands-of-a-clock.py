class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        
        minute_angle = minutes * 6
        hour_angle = (hour % 12) * 30 + minutes * 0.5
        
        diff = abs(hour_angle - minute_angle)
        
        return min(diff, 360 - diff)

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna