class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    const unordered_set<int> numsSet{nums.begin(), nums.end()};
    int ans = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1] + 1)
        break;
      ans += nums[i];
    }

    while (numsSet.contains(ans))
      ++ans;

    return ans;
  }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna