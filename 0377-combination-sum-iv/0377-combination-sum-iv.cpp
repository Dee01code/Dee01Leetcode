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
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, target);
    }
};