class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {

            int n = nums.size();
            vector<long long> presum(n, 0), lastsum(n, 0);
            long long fsum = 0, lsum = 0;

            for (int i = 0; i < n; i++)
            {
                fsum += nums[i];
                presum[i] = fsum;
                lastsum[n - i - 1] = lsum;
                lsum += nums[n - i - 1];
            }

            long long minAD = INT_MAX;
            int ans = -1;
            long long tempAD;
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    tempAD = presum[i] / (i + 1);
                }
                else
                {
                    tempAD = abs(presum[i] / (i + 1) - lastsum[i] / (n - i - 1));
                }
                if (tempAD < minAD)
                {
                    minAD = tempAD;
                    ans = i;
                }
            }
            return ans;
        }
};