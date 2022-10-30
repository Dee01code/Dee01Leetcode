class Solution
{
    public:

        int sd(long long n)
        {
            int ans = 0;
            while (n != 0)
            {
                ans += n % 10;
                n /= 10;
            }
            return ans;
        }

    long long makeIntegerBeautiful(long long n, int t)
    {

        if (sd(n) <= t) return 0;
        long long temp = n;
        long long cnt = 1;
        while (sd(temp) > t)
        {
            temp = temp / 10 + 1;
            cnt *= 10;
        }
        return temp *cnt - n;
    }
};