#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater;

        // Step 1: Find next greater elements for nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Step 2: Assign -1 to remaining elements
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Step 3: Build the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};