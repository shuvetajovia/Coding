class Solution {
    // Cache for memoization
    private int[] stoneValue;
    private Integer[] memo;
    private int n;

    /**
     * Determines the winner of the Stone Game III.
     */
    public String stoneGameIII(int[] stoneValue) {
        this.n = stoneValue.length;
        this.memo = new Integer[n];
        this.stoneValue = stoneValue;

        // Calculate the maximum score difference Alice can achieve
        int scoreDifference = dfs(0);

        // Determine the winner
        if (scoreDifference == 0) {
            return "Tie";
        }

        return scoreDifference > 0 ? "Alice" : "Bob";
    }

    /**
     * Calculates the maximum score difference the current player
     * can achieve starting from index i.
     */
    private int dfs(int i) {
        // Base case: no stones left
        if (i >= n) {
            return 0;
        }

        // Return cached result if already computed
        if (memo[i] != null) {
            return memo[i];
        }

        int maxScoreDifference = Integer.MIN_VALUE;
        int currentSum = 0;

        // Try taking 1, 2, or 3 stones
        for (int j = 0; j < 3 && i + j < n; j++) {
            // Add current stone value
            currentSum += stoneValue[i + j];

            // Current player's score - opponent's best score
            maxScoreDifference = Math.max(
                maxScoreDifference,
                currentSum - dfs(i + j + 1)
            );
        }

        // Store result in memo
        memo[i] = maxScoreDifference;

        return maxScoreDifference;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna