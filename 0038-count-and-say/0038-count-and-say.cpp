class Solution
{
    public:
        string countAndSay(int n)
        {
            if (n == 1) return "1";
            string small = countAndSay(n - 1);
            small += '#';
            string ans = "";
            int cnt = 0;
            char k = small[0];
            for (char c: small)
            {
                if (c != k)
                {
                    ans += (cnt + '0');
                    ans += k;
                    cnt = 0;
                }
                k = c;
                cnt++;
            }
            return ans;
        }
};