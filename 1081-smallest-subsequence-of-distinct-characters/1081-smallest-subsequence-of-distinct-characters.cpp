class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        
        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> inStack(26, false);
        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if already included
            if (inStack[c - 'a']) continue;

            // Maintain lexicographically smallest order
            while (!st.empty() &&
                   c < st.back() &&
                   last[st.back() - 'a'] > i) {
                inStack[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            inStack[c - 'a'] = true;
        }

        return st;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna