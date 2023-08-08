class Solution {
public:
    int search(vector<int>& nums, int t) {
        int st = 0;
        int end = nums.size();
        while(st<end){
            int mid = st - (st-end)/2;
            if(nums[mid] == t) return mid;
            else if(t >= nums[0]){
                if(t > nums[mid] && nums[mid] >= nums[0] ){
                    st = mid+1;
                } 
                else if(t > nums[mid] && nums[mid] < nums[0]){
                    end = mid;
                }
                else if(t < nums[mid]){
                    end = mid;
                }
            }
            else{
                
                if(t < nums[mid] && nums[mid] >= nums[0]){
                    st = mid+1;
                }
                else if(t < nums[mid] && nums[mid] < nums[0]){
                    end = mid;
                }
                else if(t > nums[mid]){
                    st = mid+1;
                }
            }
        }
        return -1;
    }
};