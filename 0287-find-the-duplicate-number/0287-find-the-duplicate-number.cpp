class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        for(int i = 0; i<nums.size(); i++){
            if(nums[n - abs(nums[i])] < 0) return abs(nums[i]);
            nums[n - abs(nums[i])] = -nums[n - abs(nums[i])];
        }
        return -1;
    }
};