class Solution:
    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        MOD = 10**9 + 7
        n = len(edges) + 1

        # build graph
        graph = [[] for _ in range(n + 1)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # find maximum depth
        max_depth = 0

        def dfs(node, parent, depth):
            nonlocal max_depth
            max_depth = max(max_depth, depth)

            for nei in graph[node]:
                if nei != parent:
                    dfs(nei, node, depth + 1)

        dfs(1, -1, 0)

        # number of odd sums possible
        return pow(2, max_depth - 1, MOD)

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna