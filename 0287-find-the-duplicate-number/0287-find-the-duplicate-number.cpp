class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size()-1;
        
        // for(int i = 0; i<nums.size(); i++){
        //     if(nums[n - abs(nums[i])] < 0) return abs(nums[i]);
        //     nums[n - abs(nums[i])] = -nums[n - abs(nums[i])];
        // }
        // return -1;
        
        int low=1,high=n;
        while(low < high){
            int mid = low+(high-low)/2;
            int cnt = 0;
            for(auto i : nums){
                if(i <= mid) cnt++;
            }
            if(cnt <= mid) low = mid+1;
            else high = mid;
        }
        return low;
    }
};