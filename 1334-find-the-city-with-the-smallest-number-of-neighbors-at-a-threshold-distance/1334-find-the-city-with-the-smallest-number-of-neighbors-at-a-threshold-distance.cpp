class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        // Step 1: Initialize
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        
        // Step 2: Fill edges
        for (auto &e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        
        // Step 3: Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        // Step 4: Find answer
        int minCount = INT_MAX;
        int city = -1;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            
            // Important: tie → take larger index
            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }
        
        return city;
    }
};