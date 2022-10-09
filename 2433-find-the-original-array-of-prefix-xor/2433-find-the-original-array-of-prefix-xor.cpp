class Solution
{
    public:
        vector<int> findArray(vector<int> &pref)
        {

            int prevXor = 0;
            int n = pref.size();
            vector<int> ans(n, -1);
            for (int i = 0; i < n; i++)
            {
                ans[i] = prevXor ^ pref[i];
                prevXor = pref[i];
            }
            return ans;
        }
};