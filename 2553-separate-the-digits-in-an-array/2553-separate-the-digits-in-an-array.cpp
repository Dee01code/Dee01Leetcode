class Solution
{
    public:
        vector<int> separateDigits(vector<int> &nums)
        {

            vector<int> ans;
            for (auto j: nums)
            {
                string s = to_string(j);
                cout << s << " ";
                int size = s.size();
                int i = 0;
                while (i < size)
                {
                    ans.push_back((s[i]) - '0');
                    i++;
                }
            }
            return ans;
        }
};