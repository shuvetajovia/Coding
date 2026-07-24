class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<char> dp1(MAXX, 0), dp2(MAXX, 0), dp3(MAXX, 0);

        for (int x : nums) {
            // Update in reverse order to avoid reusing the same element.
            for (int v = 0; v < MAXX; v++) {
                if (dp2[v]) dp3[v ^ x] = 1;
            }
            for (int v = 0; v < MAXX; v++) {
                if (dp1[v]) dp2[v ^ x] = 1;
            }
            dp1[x] = 1;
        }

        vector<char> ans(MAXX, 0);

        // Values obtainable using repeated indices.
        for (int x : nums)
            ans[x] = 1;

        // Values obtainable from three distinct indices.
        for (int v = 0; v < MAXX; v++)
            if (dp3[v]) ans[v] = 1;

        int res = 0;
        for (int v = 0; v < MAXX; v++)
            res += ans[v];

        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna