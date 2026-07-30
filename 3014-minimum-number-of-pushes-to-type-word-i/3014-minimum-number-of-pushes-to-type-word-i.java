class Solution {
    public int minimumPushes(String word) {
        // Length of the word
        int wordLength = word.length();

        // Stores the total minimum pushes
        int totalPushes = 0;

        // Number of pushes required for the current layer
        // First 8 letters -> 1 push
        // Next 8 letters -> 2 pushes
        // Next 8 letters -> 3 pushes, etc.
        int pushesPerChar = 1;

        // Number of complete groups of 8 letters
        int completeGroups = wordLength / 8;

        // Process each complete group
        for (int groupIndex = 0; groupIndex < completeGroups; groupIndex++) {

            // Every complete group has 8 letters
            // Each letter requires 'pushesPerChar' pushes
            totalPushes += pushesPerChar * 8;

            // Move to the next layer
            pushesPerChar++;
        }

        // Remaining letters after complete groups
        int remainingChars = wordLength % 8;

        // Add pushes for the remaining letters
        totalPushes += pushesPerChar * remainingChars;

        // Return the minimum number of pushes
        return totalPushes;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna