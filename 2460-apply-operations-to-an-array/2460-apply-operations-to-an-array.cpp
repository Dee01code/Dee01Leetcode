class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        
        int i = 0;
        
        for(auto j : nums)
            if(j != 0) nums[i++] = j;
        
        while(i<n){
            nums[i++] = 0;
        }
        
        return nums;
    }
};