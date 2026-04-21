class Solution {
public:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> parent;

    void backtrack(string word, string beginWord, vector<string>& path) {
        if(word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        
        for(string p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while(!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            for(int i = 0; i < size; i++) {
                string word = q.front(); q.pop();

                for(int j = 0; j < word.size(); j++) {
                    string temp = word;
                    for(char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;

                        if(dict.count(temp)) {
                            if(!visited.count(temp)) {
                                if(!levelVisited.count(temp)) {
                                    q.push(temp);
                                    levelVisited.insert(temp);
                                }
                                parent[temp].push_back(word);

                                if(temp == endWord)
                                    found = true;
                            }
                        }
                    }
                }
            }

            for(auto w : levelVisited)
                visited.insert(w);
        }

        if(!found) return {};

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, path);

        return res;
    }
};