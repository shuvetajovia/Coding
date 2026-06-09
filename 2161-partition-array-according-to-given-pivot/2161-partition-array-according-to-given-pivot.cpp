class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();

        // vector to array
        int arr[n];

        for(int i = 0; i < n; i++) {
            arr[i] = nums[i];
        }

        vector<int> ans;

        // smaller than pivot
        for(int i = 0; i < n; i++) {
            if(arr[i] < pivot) {
                ans.push_back(arr[i]);
            }
        }

        // equal to pivot
        for(int i = 0; i < n; i++) {
            if(arr[i] == pivot) {
                ans.push_back(arr[i]);
            }
        }

        // greater than pivot
        for(int i = 0; i < n; i++) {
            if(arr[i] > pivot) {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna