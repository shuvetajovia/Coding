class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int p1 = nums[n-1] * nums[n-2] * nums[n-3];
        int p2 = nums[0] * nums[1] * nums[n-1];

        return max(p1, p2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna