class Solution {

    // Stores the input array so it can be accessed inside dfs()
    private int[] nums;

    // Memoization table
    // dp[i][j] = Maximum score difference the current player can achieve
    // from the subarray nums[i...j]
    private int[][] dp;

    // Main function
    public boolean predictTheWinner(int[] nums) {

        this.nums = nums;
        int n = nums.length;

        // Create DP table
        dp = new int[n][n];

        // If score difference >= 0, Player 1 wins or ties
        return dfs(0, n - 1) >= 0;
    }

    // Returns maximum score difference
    private int dfs(int left, int right) {

        // Base case: No numbers left
        if (left > right) {
            return 0;
        }

        // Return memoized answer
        if (dp[left][right] != 0) {
            return dp[left][right];
        }

        // Pick left number
        int chooseLeft = nums[left] - dfs(left + 1, right);

        // Pick right number
        int chooseRight = nums[right] - dfs(left, right - 1);

        // Store the better choice
        dp[left][right] = Math.max(chooseLeft, chooseRight);

        return dp[left][right];
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna