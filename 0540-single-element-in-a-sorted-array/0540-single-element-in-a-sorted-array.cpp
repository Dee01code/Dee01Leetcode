class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        
        int st = 0;
        int end = nums.size();
        
        while(st < end){
            
            int mid = st+(end-st)/2;
            
            if((mid % 2 == 0 && mid+1 < nums.size() && nums[mid+1] == nums[mid]) || (mid % 2 == 1 && nums[mid-1] == nums[mid])) 
                st = mid+1;
            else end = mid;
            
        }
        return nums[end];
        
        
    }
};