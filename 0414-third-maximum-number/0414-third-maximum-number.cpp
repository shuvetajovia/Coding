class Solution {
public:
    int thirdMax(vector<int>& nums) {

        int n = nums.size();

        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        // first maximum
        for(int i = 0; i < n; i++) {
            if(nums[i] > max1) {
                max1 = nums[i];
            }
        }

        // second distinct maximum
        for(int i = 0; i < n; i++) {
            if(nums[i] > max2 && nums[i] != max1) {
                max2 = nums[i];
            }
        }

        // third distinct maximum
        for(int i = 0; i < n; i++) {
            if(nums[i] > max3 &&
               nums[i] != max1 &&
               nums[i] != max2) {

                max3 = nums[i];
            }
        }

        // if third max doesn't exist
        if(max3 == LONG_MIN) {
            return max1;
        }

        return max3;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna