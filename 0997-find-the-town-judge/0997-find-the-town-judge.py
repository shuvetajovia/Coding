class Solution(object):
    def findJudge(self, n, trust):
        """
        :type n: int
        :type trust: List[List[int]]
        :rtype: int
        """
        if n == 1 and not trust:
            return 1
        
        trust_count = [0] * (n + 1)
        
        for a, b in trust:
            trust_count[a] -= 1  # a trusts someone, can't be judge
            trust_count[b] += 1  # b is trusted by someone
        
        for i in range(1, n + 1):
            if trust_count[i] == n - 1:
                return i
        
        return -1
