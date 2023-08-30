class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int len = nums.size();
        
        long long ans = 0;
        int prev = nums[len-1];
        for(int i = len-2; i >= 0; i--){
            
            if(nums[i] <= prev) {
                prev = nums[i];
                continue;
            }    
            
            int parts = nums[i]/prev;
            
            if(nums[i] % prev != 0){
                parts++;
            }
            
            prev = nums[i]/parts;
            ans += parts-1;
        }
        return ans;
        
    }
};