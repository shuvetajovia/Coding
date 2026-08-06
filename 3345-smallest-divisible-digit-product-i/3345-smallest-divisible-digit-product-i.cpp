class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int num = n; num < n + 10; ++num) {
            if (getDigitProd(num) % t == 0)
                return num;
        }
        return -1;   // If no such number exists
    }

private:
    int getDigitProd(int num) {
        int digitProd = 1;

        while (num > 0) {
            digitProd *= (num % 10);
            num /= 10;
        }

        return digitProd;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna