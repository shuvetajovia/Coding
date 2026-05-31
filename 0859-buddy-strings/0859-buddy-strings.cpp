class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        if (s == goal) {
            vector<int> freq(26, 0);

            for (char c : s) {
                freq[c - 'a']++;

                if (freq[c - 'a'] > 1)
                    return true;
            }

            return false;
        }

        vector<int> diff;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i])
                diff.push_back(i);
        }

        if (diff.size() != 2)
            return false;

        int i = diff[0];
        int j = diff[1];

        return s[i] == goal[j] && s[j] == goal[i];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna