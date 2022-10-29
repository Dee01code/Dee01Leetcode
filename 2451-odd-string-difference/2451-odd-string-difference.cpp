class Solution
{
    public:
        string oddString(vector<string> &words)
        {
            vector<vector < int>> ans(words.size());

            int n = words[0].size();
            for (int j = 0; j < words.size(); j++)
            {
                vector<int> temp;
                for (int i = 1; i < n; i++)
                {
                    temp.push_back(words[j][i] - words[j][i - 1]);
                }
                ans[j] = temp;
            }

            int k = 0;
            while (k < words.size())
            {
                if (k == 0)
                {
                    if (ans[k] != ans[k + 1] && ans[k] != ans[k + 2]) return words[k];
                }
                else if (k == words.size() - 1)
                {
                    return words[k];
                }
                else if (ans[k] != ans[k - 1] && ans[k] != ans[k + 1]) return words[k];
                k++;
            }

            return "";
        }
};