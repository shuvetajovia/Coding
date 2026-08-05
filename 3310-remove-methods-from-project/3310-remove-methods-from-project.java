import java.util.*;

class Solution {

    private boolean[] isSuspicious;
    private boolean[] isVisited;

    private List<Integer>[] undirectedGraph;
    private List<Integer>[] directedGraph;

    public List<Integer> remainingMethods(
            int n,
            int k,
            int[][] invocations
    ) {

        // Initialize arrays
        isSuspicious = new boolean[n];
        isVisited = new boolean[n];

        // Initialize adjacency lists
        undirectedGraph = new ArrayList[n];
        directedGraph = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            undirectedGraph[i] = new ArrayList<>();
            directedGraph[i] = new ArrayList<>();
        }

        // Build the graphs
        for (int[] invocation : invocations) {

            int caller = invocation[0];
            int callee = invocation[1];

            // Undirected graph
            undirectedGraph[caller].add(callee);
            undirectedGraph[callee].add(caller);

            // Directed graph
            directedGraph[caller].add(callee);
        }

        // Step 1: Find all suspicious methods
        markSuspicious(k);

        // Step 2: Check whether suspicious methods
        // are connected to any non-suspicious method
        for (int method = 0; method < n; method++) {

            if (!isSuspicious[method] && !isVisited[method]) {
                markConnectedAsSafe(method);
            }
        }

        // Step 3: Collect remaining methods
        List<Integer> result = new ArrayList<>();

        for (int method = 0; method < n; method++) {

            if (!isSuspicious[method]) {
                result.add(method);
            }
        }

        return result;
    }

    /*
     * DFS to find all methods that are reachable
     * from the buggy method k.
     */
    private void markSuspicious(int currentMethod) {

        isSuspicious[currentMethod] = true;

        for (int nextMethod : directedGraph[currentMethod]) {

            if (!isSuspicious[nextMethod]) {
                markSuspicious(nextMethod);
            }
        }
    }

    /*
     * DFS to find methods connected to a non-suspicious method.
     * If a suspicious method is reached, it cannot be removed.
     */
    private void markConnectedAsSafe(int currentMethod) {

        isVisited[currentMethod] = true;

        for (int nextMethod : undirectedGraph[currentMethod]) {

            if (!isVisited[nextMethod]) {

                // This method is connected to a safe method,
                // so it must also remain in the project.
                isSuspicious[nextMethod] = false;

                markConnectedAsSafe(nextMethod);
            }
        }
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna