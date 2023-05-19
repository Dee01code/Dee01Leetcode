class Solution {
public:
    
    int solve(vector<int> cost, int n, vector<int> &dp){
        if(n<=1) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = min(solve(cost,n-1,dp) + cost[n-1] , solve(cost,n-2,dp)+cost[n-2]);
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
        
        vector<int> table(n);
        table[0] = cost[0];
        table[1] = cost[1];
        
        for(int i = 2; i<n; i++){
            table[i] = min(table[i-1],table[i-2])+cost[i];
        }
        return min(table[n-1],table[n-2]);
        // return min(side0(cost,0,n,dp),side0(cost,1,n,dp));
        // return solve(cost,n,dp);
    }
};