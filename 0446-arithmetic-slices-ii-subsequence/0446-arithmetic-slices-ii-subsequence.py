class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        res = 0
        dp = [defaultdict(int) for i in range(len(nums))]
		
        for i in range(1, len(nums)):
            for j in range(i):
                dif = nums[i]-nums[j]
                dp[i][dif] += 1
                if dif in dp[j]:
                    dp[i][dif] += dp[j][dif]
                    res += dp[j][dif]
        return res