class Solution {

    public long countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        int size = 2 * n + 5;
        int[] bit = new int[size];

        int offset = n + 2;

        update(bit, offset);

        int prefix = 0;
        long answer = 0;

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            answer += query(bit, prefix + offset - 1);
            update(bit, prefix + offset);
        }

        return answer;
    }

    private void update(int[] bit, int index) {
        while (index < bit.length) {
            bit[index]++;
            index += index & -index;
        }
    }

    private int query(int[] bit, int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna