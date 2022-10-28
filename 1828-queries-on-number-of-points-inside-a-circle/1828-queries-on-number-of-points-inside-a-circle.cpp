class Solution
{
    public:

        vector<int> countPoints(vector<vector < int>> &p, vector< vector< int>> &q)
        {

            vector<int> ans;
            for (auto i: q)
            {
                int cnt = 0;
                int x1 = i[0];
                int y1 = i[1];
                for (auto j: p)
                {
                    int x2 = j[0];
                    int y2 = j[1];
                    if (pow((x1 - x2), 2) + pow((y1 - y2), 2) <= i[2] *i[2]) cnt++;
                }
                ans.push_back(cnt);
            }
            return ans;
        }
};