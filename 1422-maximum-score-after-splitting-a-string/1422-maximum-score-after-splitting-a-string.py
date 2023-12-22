class Solution:
    def maxScore(self, s: str) -> int:
        l = list(s)
        ans = 0
        for i in range(1,len(s)):
            left = l[:i].count('0')
            right = l[i:].count('1')
            # print(left, right)
            ans = max(left+right,ans)
        return ans
        