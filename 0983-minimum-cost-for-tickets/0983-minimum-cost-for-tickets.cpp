class Solution {
public:
    int max_day, cost[5], dys[500], dp[500];

    int solve(int id) {
        if(id > 365) return 0;
        if(dp[id] != -1) return dp[id];

        int ans;
        if(dys[id]) {
            ans = min({cost[0] + solve(id+1), cost[1] + solve(id+7), cost[2] + solve(id+30)});
        }
        else {
            ans = solve(id+1);
        }
        return dp[id] = ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=0; i<3; i++) cost[i] = costs[i];
        for(int i=0; i<500; i++) dp[i] = -1;
        for(int i=0; i<days.size(); i++) dys[days[i]] = 1;
        int ans = solve(0);
        return ans;
    }
};