class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        int[] temp = new int[n];
        int idx = 0;

        // last k elements
        for (int i = n - k; i < n; i++) {
            temp[idx++] = nums[i];
        }

        // first n-k elements
        for (int i = 0; i < n - k; i++) {
            temp[idx++] = nums[i];
        }

        // copy back
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
    }
}
