import collections

class Solution:
    def __init__(self):
        self.MAX = 1000001

    def smallestPalindrome(self, s, k):
        count = collections.Counter(s)

        halfCount = [0] * 26
        midLetter = ''

        for c, freq in count.items():
            halfCount[ord(c) - ord('a')] = freq // 2

            if freq % 2 == 1:
                midLetter = c

        totalPerm = self.countArrangements(halfCount)

        if k > totalPerm:
            return ''

        left = []

        for pos in range(sum(halfCount)):
            for i in range(26):

                if halfCount[i] == 0:
                    continue

                halfCount[i] -= 1

                ways = self.countArrangements(halfCount)

                if ways >= k:
                    left.append(chr(i + ord('a')))
                    break
                else:
                    k -= ways
                    halfCount[i] += 1

        left = ''.join(left)

        return left + midLetter + left[::-1]

    def countArrangements(self, count):
        total = sum(count)
        result = 1

        for freq in count:
            if freq == 0:
                continue

            result *= self.nCk(total, freq)

            if result >= self.MAX:
                return self.MAX

            total -= freq

        return result

    def nCk(self, n, k):
        k = min(k, n - k)

        result = 1

        for i in range(1, k + 1):
            result = result * (n - i + 1) // i

            if result >= self.MAX:
                return self.MAX

        return result

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna