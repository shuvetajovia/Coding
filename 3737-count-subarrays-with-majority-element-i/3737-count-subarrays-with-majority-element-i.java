class Solution {
    static class Fenwick {
        int[] bit;

        Fenwick(int n) {
            bit = new int[n + 1];
        }

        void update(int idx, int val) {
            while (idx < bit.length) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    }

    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;

        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        int[] all = prefix.clone();
        java.util.Arrays.sort(all);

        java.util.Map<Integer, Integer> rank = new java.util.HashMap<>();
        int idx = 1;
        for (int x : all) {
            if (!rank.containsKey(x)) {
                rank.put(x, idx++);
            }
        }

        Fenwick ft = new Fenwick(idx);
        long ans = 0;

        for (int p : prefix) {
            int r = rank.get(p);

            ans += ft.query(r - 1); // count previous prefix sums < current

            ft.update(r, 1);
        }

        return (int) ans;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna