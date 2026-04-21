class Solution {
public:
    int mergeSort(vector<long>& sums, int l, int r, int lower, int upper) {
        if(r - l <= 1) return 0;

        int mid = (l + r) / 2;
        int count = mergeSort(sums, l, mid, lower, upper) +
                    mergeSort(sums, mid, r, lower, upper);

        int j = mid, k = mid, t = mid;
        vector<long> temp;
        int idx = 0;

        for(int i = l; i < mid; i++) {
            while(k < r && sums[k] - sums[i] < lower) k++;
            while(j < r && sums[j] - sums[i] <= upper) j++;
            count += (j - k);
        }

        // merge step
        int p = l, q = mid;
        while(p < mid && q < r) {
            if(sums[p] <= sums[q])
                temp.push_back(sums[p++]);
            else
                temp.push_back(sums[q++]);
        }

        while(p < mid) temp.push_back(sums[p++]);
        while(q < r) temp.push_back(sums[q++]);

        for(int i = 0; i < temp.size(); i++)
            sums[l + i] = temp[i];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);

        for(int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];

        return mergeSort(sums, 0, n + 1, lower, upper);
    }
};