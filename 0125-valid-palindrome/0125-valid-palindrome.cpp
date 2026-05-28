class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char c : s) {
            if (isalnum(c))
                str += tolower(c);
        }
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna