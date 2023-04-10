class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        int low = 0;
        int high = 1e9;
        
        sort(nums.begin(), nums.end());
        
        while(low < high){
            
            int mid = low + (high - low)/2;
            int cnt=0;
            for(int i = 1; i<nums.size(); i++){
                if(nums[i]-nums[i-1] <= mid){
                    cnt++;
                    i++;
                }
            }
            
            if(cnt >= p) high = mid;
            else low = mid+1;
            
        }
        return low;
    }
};