class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool rise=1, down=1;
        
        for(int i=1; i<nums.size(); i++){
            rise &= nums[i-1]<=nums[i];
            down &= nums[i-1]>=nums[i];
        }
        return rise||down;
        
    }
};