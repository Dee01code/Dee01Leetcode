class Solution
{
    public:
        string frequencySort(string s)
        {
            map<char, int> m;
            for (auto i: s)
            {
                m[i]++;
            }
            map<int, vector < char>> m2;
            for (auto i: m)
            {
               	// cout << i.first << i.second;
                m2[i.second].push_back(i.first);
            }
           	// cout << endl;
            string ans = "";
            for (auto i: m2)
            {
               	// cout << i.first << i.second <<" ";  
                int j = i.first;
                for (auto k: i.second)
                {
                    int num = j;
                    while (num--)
                    {
                        ans += k;
                    }
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};