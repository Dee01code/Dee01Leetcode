class Solution
{
    public:
        int vowelStrings(vector<string> &words, int left, int right)
        {
            unordered_map<char, int> m;
            m['a'] = 1;
            m['e'] = 1;
            m['i'] = 1;
            m['o'] = 1;
            m['u'] = 1;
            int cnt = 0;
            for (int i = left; i <= right; i++)
            {
                char st = words[i][0];
                char end = words[i][words[i].size() - 1];
                if (m.count(st) && m.count(end))
                {
                    cout << words[i] << " ";
                    cnt++;
                }
            }
            return cnt;
        }
};