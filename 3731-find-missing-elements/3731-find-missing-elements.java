class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int mn = 100, mx = 0;
        Set<Integer> s = new HashSet<>();
        for (int x : nums) {
            mn = Math.min(mn, x);
            mx = Math.max(mx, x);
            s.add(x);
        }
        List<Integer> ans = new ArrayList<>();
        for (int x = mn + 1; x < mx; ++x) {
            if (!s.contains(x)) {
                ans.add(x);
            }
        }
        return ans;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna