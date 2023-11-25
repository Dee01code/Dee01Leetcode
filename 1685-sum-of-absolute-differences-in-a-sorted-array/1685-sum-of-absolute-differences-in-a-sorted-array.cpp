class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> preSum(n,0);
        preSum[0] = nums[0];
        
        for(int i = 1; i < n; i++) preSum[i] = preSum[i-1] + nums[i];
        
        vector<int> ans(n,0);
        
        for(int i = 0; i<n; i++){
            int prevSum = 0, nextSum = 0;
            if(i>0){
                prevSum = preSum[i-1];
                prevSum = i*nums[i] - prevSum;
            }
            if(i < n-1){
                nextSum = preSum[n-1] - preSum[i];
                nextSum -= (n-i-1)*nums[i];
            }
            ans[i] = nextSum + prevSum;
        }
        
        return ans;
        
    }
};