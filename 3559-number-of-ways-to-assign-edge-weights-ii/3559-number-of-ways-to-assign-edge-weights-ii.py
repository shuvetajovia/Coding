class Solution:
    def assignEdgeWeights(self, edges: List[List[int]], queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(edges) + 1

        adj = [[] for _ in range(n + 1)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        LOG = 17

        parent = [[0] * (n + 1) for _ in range(LOG)]
        depth = [0] * (n + 1)

        stack = [1]
        visited = [False] * (n + 1)
        visited[1] = True

        while stack:
            node = stack.pop()

            for nei in adj[node]:
                if not visited[nei]:
                    visited[nei] = True
                    depth[nei] = depth[node] + 1
                    parent[0][nei] = node
                    stack.append(nei)

        for k in range(1, LOG):
            for i in range(1, n + 1):
                parent[k][i] = parent[k - 1][parent[k - 1][i]]

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            diff = depth[u] - depth[v]

            for k in range(LOG):
                if diff & (1 << k):
                    u = parent[k][u]

            if u == v:
                return u

            for k in range(LOG - 1, -1, -1):
                if parent[k][u] != parent[k][v]:
                    u = parent[k][u]
                    v = parent[k][v]

            return parent[0][u]

        max_len = n + 1
        pow2 = [1] * max_len

        for i in range(1, max_len):
            pow2[i] = (pow2[i - 1] * 2) % MOD

        ans = []

        for u, v in queries:
            L = lca(u, v)

            path_len = depth[u] + depth[v] - 2 * depth[L]

            if path_len == 0:
                ans.append(0)
            else:
                ans.append(pow2[path_len - 1])

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna