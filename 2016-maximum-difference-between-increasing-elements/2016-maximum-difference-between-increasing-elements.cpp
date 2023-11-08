class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> mini(n,0);
        mini[0] = nums[0];
        for(int i = 1; i<n; i++){
            mini[i] = min(mini[i-1], nums[i]);
        }
        
        int result = INT_MIN;
        for(int i = 1; i<n; i++){
            result = max(nums[i]-mini[i-1], result);
        }
        if(result > 0) return result;
        return -1;
    }
};