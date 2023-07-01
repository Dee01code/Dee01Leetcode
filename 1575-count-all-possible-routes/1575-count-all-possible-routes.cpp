class Solution {
    private:
    int mod = 7+1e9;
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>>dp(locations.size()+1, vector<int>(fuel+1, -1));
        return solve(locations, start, finish, fuel, dp);
    }

    int solve(vector<int>& locations, int current, int& finish, int currentfuel, vector<vector<int>>& dp)
    {
        int ans = 0;
        if(current == finish)
        {
            ans = 1;
        }
        if(currentfuel == 0)
        {
            return ans;
        }
        if(dp[current][currentfuel] != -1)
        {
            return dp[current][currentfuel];
        }
        for(int i = 0;i < locations.size(); i++)
        {
            if(i != current && (currentfuel - abs(locations[current]-locations[i])) >= 0)
            {
                ans = (ans + (solve(locations, i, finish, currentfuel-abs(locations[current]-locations[i]), dp))%mod)%mod;
            }
        }
        return dp[current][currentfuel] = ans%mod;
    }
};