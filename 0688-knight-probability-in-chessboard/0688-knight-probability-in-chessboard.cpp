class Solution
{
    public:
        vector<vector<vector< double>>> dp;
    vector<pair<int, int>> state;
    double rec(int row, int col, int n, int k)
    {
        if (row >= n || col >= n || row < 0 || col < 0) return 0;
        if (k == 0) return 1.0;
        if (dp[row][col][k] != (-1.0)) return dp[row][col][k];

        double ans = 0.0;

        for (int i = 0; i < 8; i++)
        {
            ans += ((1.0 / 8.0) *(rec(row + state[i].first, col + state[i].second, n, k - 1)));
        }

        return dp[row][col][k] = ans;
    }
    double knightProbability(int n, int k, int row, int col)
    {
        state = { {-1,-2} , {1,-2} , {2,-1} , {2,1} , {-1,2} , {1,2} , {-2,-1} , {-2,1} };
        dp.resize(n + 1, vector<vector < double>> (n + 1, vector<double> (k + 1, -1.0)));
        return rec(row, col, n, k);
    }
};