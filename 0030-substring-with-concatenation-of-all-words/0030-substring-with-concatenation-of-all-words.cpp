class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> target;
        for (auto &w : words) target[w]++;

        // Try all offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);

                if (target.count(word)) {
                    seen[word]++;
                    count++;

                    // shrink if extra
                    while (seen[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // valid window
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // reset
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return result;
    }
};