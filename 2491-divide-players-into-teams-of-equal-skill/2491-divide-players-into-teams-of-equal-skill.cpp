class Solution
{
    public:
        long long dividePlayers(vector<int> &s)
        {

            int n = s.size();
            int mini = INT_MAX;
            int maxi = INT_MIN;
            unordered_map<int, int> m;
            for (auto i: s)
            {
                mini = min(mini, i);
                maxi = max(maxi, i);
                m[i]++;
            }
            long long tot = mini + maxi;
            long long int ans = 0;
            for (int i = 0; i < n; i++)
            {
                long long req = tot - s[i];
                if (m[s[i]] == 0 && m[req] == 0) continue;
                if (m.find(req) != m.end() && (m[req] > 0))
                {
                    ans += (req *s[i]);
                    for (auto i: m) {}
                    m[req]--;
                    m[s[i]]--;
                }
                else return -1;
            }

            return ans;
        }
};