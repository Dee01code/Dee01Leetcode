class Solution
{
    public:
        int maxCount(vector<int> &banned, int n, int maxSum)
        {
            vector<int> range(n + 1, 0);

            for (auto i: banned)
            {
                if (i < n + 1) range[i] = -1;
            }

            int ans = 0;
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                if (range[i] != -1)
                {
                    if (sum + i <= maxSum)
                    {
                        ans++;
                        sum += i;
                    }
                    if (sum >= maxSum) return ans;
                }
            }
            return ans;
        }
};