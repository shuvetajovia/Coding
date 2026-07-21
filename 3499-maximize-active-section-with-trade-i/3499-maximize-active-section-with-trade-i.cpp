class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count original active sections
        int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        // Augment with 1s
        string t = "1" + s + "1";

        vector<pair<char, int>> runs;

        // Run-length encoding
        for (char c : t) {
            if (runs.empty() || runs.back().first != c)
                runs.push_back({c, 1});
            else
                runs.back().second++;
        }

        int bestGain = 0;

        // Look for 0 - 1 - 0 pattern
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                bestGain = max(bestGain,
                               runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ones + bestGain;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna