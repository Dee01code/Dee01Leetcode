class Solution {
public:
    int dp[501][501];
    int util(vector<int>& cost, vector<int>& time, int strt, int wall_remaining){
        if(wall_remaining<=0)return 0;
        if(strt==cost.size())return 1e9;
        if(dp[strt][wall_remaining] != -1)return dp[strt][wall_remaining];

        int take=cost[strt]+util(cost, time, strt+1, wall_remaining-time[strt]-1);
        int not_take=util(cost, time, strt+1, wall_remaining);
        return dp[strt][wall_remaining]=min(take, not_take);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=time.size();
        memset(dp, -1, sizeof(dp));
        return util(cost, time, 0, n);
    }
};