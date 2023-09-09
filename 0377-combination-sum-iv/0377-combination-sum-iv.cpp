class Solution {
public:
    int dp[1001];
    int solve(vector<int> &nums, int t){
        if(t<0) return 0;
        if(t == 0) return 1;
        if(dp[t] != -1) return dp[t];
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans += solve(nums,t-nums[i]);
        }
        return dp[t] = ans;
        
    }
    
    int solveTab(vector<int>& nums, int t){
        int dp[t+1];
        memset(dp , 0, sizeof(dp));
     
        for(int i = 1; i<=t; i++){
            for(int j = 0; j<nums.size(); j++){
                if(t-nums[j] >= 0)
                    dp[i] += dp[t-nums[j]];
            }
        }
        return dp[t];
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, target);
        return solveTab(nums, target);
    }
};