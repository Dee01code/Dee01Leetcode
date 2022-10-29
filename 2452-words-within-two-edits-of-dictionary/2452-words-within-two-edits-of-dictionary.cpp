class Solution
{
    public:
        vector<string> twoEditWords(vector<string> &q, vector<string> &d)
        {
            vector<string> ans;

            int n = q[0].size();
            for (auto w: q)
            {
                for (auto j: d)
                {
                    int diff = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (diff > 2) break;
                        if (w[i] != j[i]) diff++;
                    }
                    if (diff <= 2)
                    {
                        ans.push_back(w);
                        break;
                    }
                }
            }
            return ans;
        }
};

