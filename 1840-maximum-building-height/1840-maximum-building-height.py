class Solution(object):
    def maxBuilding(self, n, restrictions):
        if not restrictions:
            return n - 1

        restrictions.append([1, 0])

        found = False
        for r in restrictions:
            if r[0] == n:
                found = True
                break

        if not found:
            restrictions.append([n, n - 1])

        restrictions.sort()

        m = len(restrictions)

        for i in range(1, m):
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                restrictions[i][0] - restrictions[i - 1][0]
            )

        for i in range(m - 2, -1, -1):
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                restrictions[i + 1][0] - restrictions[i][0]
            )

        ans = 0

        for i in range(m - 1):
            x1, h1 = restrictions[i]
            x2, h2 = restrictions[i + 1]

            dist = x2 - x1
            peak = (h1 + h2 + dist) // 2
            ans = max(ans, peak)

        return ans

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna