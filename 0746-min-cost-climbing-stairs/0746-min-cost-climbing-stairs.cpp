class Solution {
public:
    
    int solve(vector<int> cost, int n){
        if(n<=1) return 0;
        return min(solve(cost,n-1) + cost[n-1] , solve(cost,n-2)+cost[n-2]);
    }
    
    int side0(vector<int> cost, int i, int n, vector<int> &dp){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int left = side0(cost,i+1,n,dp) + cost[i];
        int right = side0(cost,i+2,n,dp) + cost[i];
        return dp[i] = min(left,right); 
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(side0(cost,0,n,dp),side0(cost,1,n,dp));
        // return solve(cost,n);
    }
};